#include <wiringPi.h>
#include <stdlib.h>

int main()
{
    if( wiringPiSetup() == -1 )
        exit( 1 );

//..............Segmentation fault...
// button 0 should be GPIO_GEN0(GPIO17)
// button 1 should be GPIO_GEN1(GPIO18)

    pinMode( 0, OUTPUT );
    pinMode( 1, INPUT );

    for (;;)
    {
        if (digitalRead (1) == 0)
        {
            digitalWrite( 0, HIGH );
            delay( 300 );
            digitalWrite( 0, LOW );
            delay( 300 );
        }
        else
            break ;
    }
}
