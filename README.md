# automatic-greenhouse
A project using an ESP32 and Adafruit IO to control a monitor a greenhouse automatically. 

This project uses an ESP32 microcontroller to publish data to the Adafruit IO platform using MQTT and displays the data in feeds on the Adafruit website. 


![1 Main_1x_DHT22AM2302TemperatursensorundLuftfeuchtigkeitssensor_6bbf04ec-fa59-464e-a1db-7d3cddbb5b1a_1024x copy](https://user-images.githubusercontent.com/58001312/178789327-3286fa4f-3e8e-4f32-b843-4666c70003e4.png)![ssldr34](https://user-images.githubusercontent.com/58001312/178789455-b13dc7d0-4518-4aad-983c-08776536f6fb.jpg)





Currently the project publishes data from a DHT22 humidity and temperature sensor and a standard photocell, the data that is published to these feeds will eventually control shades and misters in different zones of a greenhouse depending on required values for each zone compared to actual values published by the sensors. 




# Set-up

To follow this project using the Arduino IDE the board add-on must be installed so that it can be compatible with the ESP32, below is the tutorial for installing the board add-on for this specific board: 

https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/

The Adafruit MQTT package must also be installed which a tutorial can be found here:

https://learn.adafruit.com/mqtt-adafruit-io-and-you/arduino-plus-library-setup
