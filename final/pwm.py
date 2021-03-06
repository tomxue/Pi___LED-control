# softPwm uses a fixed frequency
import wiringpi2

OUTPUT = 1

# GPIO17 = GPIO_GEN0 = P1.11, connecting a red led
PIN_TO_PWM = 0

wiringpi2.wiringPiSetup()
wiringpi2.pinMode(PIN_TO_PWM,OUTPUT)
wiringpi2.softPwmCreate(PIN_TO_PWM,0,100) # Setup PWM using Pin, Initial Value and Range parameters

for time in range(0,4):
        for brightness in range(0,100): # Going from 0 to 100 will give us full off to full on
                wiringpi2.softPwmWrite(PIN_TO_PWM,brightness) # Change PWM duty cycle
                wiringpi2.delay(10) # Delay for 0.2 seconds
        for brightness in reversed(range(0,100)):
                wiringpi2.softPwmWrite(PIN_TO_PWM,brightness)
                wiringpi2.delay(10)
