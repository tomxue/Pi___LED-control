// This code is from git@github.com:phil-lavin/raspberry-pi-gpio-interrupt.git gpio-interrupt.c
#include <stdio.h>
#include <sys/time.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>

// Which GPIO pin we're using: Tom Xue, using GPIO_GEN1(GPIO18) as button input
#define PIN 1
// How much time a change must be since the last in order to count as a change
#define IGNORE_CHANGE_BELOW_USEC 10*1000

// Current state of the pin
static volatile int state;
// Time of last change
struct timeval last_change;

#define TIMER_MAX_NUM 100  //设置最大的定时器个数
int runTime=1; //runTime表示时间，逐秒递增
int timerIsRunning = 0;

struct Timer { //Timer结构体，用来保存一个定时器的信息
    int total_time;  //每隔total_time秒
    int left_time;   //还剩left_time秒
    int func;        //该定时器超时，要执行的代码的标志
} myTimer[TIMER_MAX_NUM];   //定义Timer类型的数组，用来保存所有的定时器

void setTimer(int t,int f) //新建一个计时器
{
    struct Timer a;
    a.total_time=t;
    a.left_time=t;
    a.func=f;
    myTimer[0]=a;
}

stopTimer()
{
    myTimer[0].left_time = -1;
    runTime = 0;
}

initTimer()
{
    myTimer[0].left_time = myTimer[0].total_time;
    runTime = 0;
}

void timeout()  //判断定时器是否超时，以及超时时所要执行的动作
{
    printf("Time: %d\n",runTime++);
    if(myTimer[0].left_time == -1)
        ;
    else if(myTimer[0].left_time != 0)
        myTimer[0].left_time--;
    else {
        switch(myTimer[0].func) { //通过匹配myTimer[0].func，判断下一步选择哪种操作
        case 1:
            printf("---Time: %d--- Rebooting...\n",runTime);
            system("reboot");
            break;
        case 2:
        case 3:
            break;
        }
//            myTimer[j].left_time=myTimer[j].total_time;     //循环计时
    }
}

// Handler for interrupt
void ISRHandle(void)
{
    struct timeval now;
    unsigned long diff;

    gettimeofday(&now, NULL);

    // Time difference in usec
    diff = (now.tv_sec * 1000000 + now.tv_usec) - (last_change.tv_sec * 1000000 + last_change.tv_usec);

    // Filter jitter
    if (diff > IGNORE_CHANGE_BELOW_USEC) {
        if (state) {
            printf("Falling\n");
            initTimer();
            timerIsRunning = 1;
        } else {
            printf("Rising\n");
            stopTimer();
            timerIsRunning = 0;
        }
        state = !state;
    }

    last_change = now;
}

int main(void)
{
    // Init
    wiringPiSetup();

    pinMode(PIN, INPUT);
    pullUpDnControl(PIN, PUD_UP);

    // Time now
    gettimeofday(&last_change, NULL);

    // Bind to interrupt
    wiringPiISR(PIN, INT_EDGE_BOTH, &ISRHandle);

    // Get initial state of pin
    state = digitalRead(PIN);

    if (state) {
        printf("Started! Initial state is on\n");
    } else {
        printf("Started! Initial state is off\n");
    }

    setTimer(2,1);
    signal(SIGALRM, timeout);  //接到SIGALRM信号，则执行timeout函数

    // Waste time but not CPU
    for (;;) {
        sleep(1);  //每隔一秒发送一个SIGALRM
        if(timerIsRunning)
            kill(getpid(), SIGALRM);
    }
}
