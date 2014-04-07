import RPi.GPIO as GPIO
# 17 corresponds to GPIO_GEN0(GPIO17)
# 18 corresponds to GPIO_GEN1(GPIO18)
led_pin = 17
button_pin = 18

GPIO.setwarnings(False)
GPIO.setmode( GPIO.BCM )
GPIO.setup( led_pin,GPIO.OUT )
GPIO.setup( button_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

print ("linke r_led pin 17 , linker_button pin 18 (BCM GPIO)\n")

while True:
       if GPIO.input(button_pin):
                     GPIO.output(led_pin,True)
       else :
                     GPIO.output(led_pin,False)
