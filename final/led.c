#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define HIGH        1
#define LOW         0
// GPIO17 = GPIO_GEN0 = P1.11, connecting a red led
#define PIN         0

int main (void)
{
    if (wiringPiSetup () == -1)
        exit (1) ;
    pinMode(PIN, OUTPUT);
    while(1) {
        digitalWrite(PIN, HIGH);
        usleep(200*1000);
        digitalWrite(PIN, LOW);
        usleep(200*1000);
    }
    
    return 0 ;
}
