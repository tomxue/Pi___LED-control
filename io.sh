#!/bin/bash
# Simple test - assumes LEDs on Pins 0-7.

gpio mode 0 out

while true;
do
  gpio write 0 1 # red off
  gpio write 2 1 # green off
  gpio write 3 1 # blue off

  # red
  gpio write 0 0
  sleep 0.2
  gpio write 0 1
  sleep 0.2

  # green
  gpio write 2 0
  sleep 0.2
  gpio write 2 1
  sleep 0.2

  # blue
  gpio write 3 0
  sleep 0.2
  gpio write 3 1
  sleep 0.2
done
