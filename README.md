# OlaWall
Multi pin i2S ws2812b ESP32

This has been written as a proof of concept to verify what 
can be accomplished controlling LEDs via i2S rather than RMT.

I've used the pacifica pattern to provide a typical load on the 
processor

If you comment out the first line of code for the ino file and flash 
the code to the ESP32, the leds will be refreshed using the conventional 
RMT dicipline.

Check out the serial monitor and you'll see the frame rate hovering
around 7 frames per second

Revert the first line back into the code, flash it to the ESP2 and
the leds will be refreshed usining i2S

This time when you check the serial monitor, you will see the refresh rate
soaring to 70 frames per second
