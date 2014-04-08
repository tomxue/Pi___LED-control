#include <stdlib.h>
#include <wiringPi.h>

// button 0 should be GPIO_GEN0(GPIO17)
// button 1 should be GPIO_GEN1(GPIO18)
int button_pin = 1;
int led_pin = 0;

int main ()
{
    printf("wiringPi pin\n");
    printf("linker_led pin : GPIO%d\n",led_pin);
    printf("linker_button pin : GPIO%d\n",button_pin);

    if (wiringPiSetup() == -1)
    {
        printf("Setup wiringPi failed!\n");
        return 1;
    }

    pinMode(led_pin, OUTPUT); // set linker_led mode to output
    pinMode(button_pin, INPUT); // set linker_button mode to input
    //while(1)
    {
        if( digitalRead(button_pin) )
            printf("1"); // output a high level
        else
            printf("0"); // output a low level
    }
}
