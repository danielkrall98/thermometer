# thermometer
Arduino Project for a Prototype Thermometer

---

This is an Arduino Project for University using an Arduino.

The System consists of
- LCD Display
- Potentiometer
- RGB & Blue LED
- Push Button
- Buzzer
- Temperature Sensor

---

In the beginning the display shows "Messung" (measuring) and the blue LED is blinking. <br>
Three dots cycle through twice while measuring. <br>
After Measuring, the display shows "TEMPERATUR:" (temperature) with the exact temperature being shown in the second line in Celcius with one decimal point. By using the push button, the temperature can be changed to Fahrenheit. When the button is pressed, the blue LED quickly lights up (visual feedback) and there's a quick sound from the buzzer (audio feedback). Pressing the button again reverts the temperature to Celsius. <br>
The potentiometer can be used to adjust the display's contrast. <br>
The RGB LED visualises the temperature by lighting up in different colours.
- WHITE: below 0°C
- BLUE: between 0°C and 10°C
- GREEN: between 10°C and 20°C
- YELLOW: between 20°C and 30°C
- RED: above 30°C

---

In a real-life application, either several LEDs or a LED stripe would be used for better visualisation. <br>
The temperature sensor can be built into the thermometer (measuring at the spot where the thermometer is located) or a seperate sensor can be connected via cable (to e.g. mount the thermometer inside the house with the sensor outside).
