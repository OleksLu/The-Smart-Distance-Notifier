# The Smart Distance Notifier
**_Project Overview:_**
  The Smart Distance Notifier is an Arduino-based project designed to measure distances using an ultrasonic sensor (HC-SR04) and provide real-time feedback through an OLED display and    an audible alarm. The system helps users maintain social distancing in public spaces by alerting them when an object or person is too close.

**Key Features:**
* Distance Measurement: Utilizes an ultrasonic sensor to accurately measure distances in centimeters.
* Visual Feedback: Displays real-time distance information on a compact OLED display.
* Audible Alarm: Generates a warning sound if the measured distance is below a predefined threshold.
* User-Friendly: Portable and easy to use, making it suitable for various environments.


**Technologies Used:**
 * Arduino (C++ programming language)
 * HC-SR04 Ultrasonic Sensor
 * OLED Display with I2C interface
 * Passive Buzzer for audible alerts

**Hardware Requirements:**
 * Arduino board
 * HC-SR04 Ultrasonic Sensor
 * OLED Display (I2C)
 * Passive Buzzer
 * Breadboard and jumper wires

**Software Requirements:**
Arduino IDE with necessary libraries (Adafruit_SSD1306, NewTone, Wire, Adafruit_GFX)

**Installation Guide:**
  * Connect the components according to the provided circuit diagram.
  * Install the required libraries in the Arduino IDE.
  * Upload the provided Arduino code to the board.

**Usage:**
  * Power on the device.
  * The OLED display shows the real-time distance measurement.
  * If an object or person comes too close (below a defined threshold), the buzzer emits a warning sound.
