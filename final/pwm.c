#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// GPIO17 = GPIO_GEN0 = P1.11, connecting a red led
#define PIN         0
#define PWM_RANGE   100

int main (void)
{
    int brightness ;
    printf ("Raspberry Pi wiringPi PWM test program\n") ;
    if (wiringPiSetup () == -1)
        exit (1) ;
    pinMode (PIN, PWM_OUTPUT);
    softPwmCreate(PIN, 0, PWM_RANGE);

    for (;;) {
        for (brightness = 0 ; brightness < PWM_RANGE ; ++brightness) {
//            pwmWrite (PIN, brightness) ;
            softPwmWrite(PIN, brightness);
            delay (10) ;
        }
        for (brightness = PWM_RANGE-1 ; brightness >= 0 ; --brightness) {
//            pwmWrite (PIN, brightness) ;
            softPwmWrite(PIN, brightness);
            delay (10) ;
        }
    }
    return 0 ;
}
