#!/bin/bash
# Simple test - assumes LEDs on Pins 0-7.

gpio mode 0 out

gpio write 0 0 # red off
#gpio write 0 1 # red on
