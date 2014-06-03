#!/bin/bash
# Simple test - assumes LEDs on Pins 0-7.

gpio mode 0 out

gpio write 0 1 # red off
gpio write 2 1 # green off
gpio write 3 1 # blue off

# red
gpio write 0 0
