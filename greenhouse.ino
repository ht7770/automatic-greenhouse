
#include "config.h"

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// pin connected to DH22 data line
#define DATA_PIN 14

// pin photocell connected to
int photocellPin = 32;

// create DHT22 instance
DHT_Unified dht(DATA_PIN, DHT22);

// set up the 'temperature', 'photocell' and 'humidity' feeds for sending data 
AdafruitIO_Feed *photocell = io.feed("photocell");
AdafruitIO_Feed *temperature = io.feed("temperature");
AdafruitIO_Feed *humidity = io.feed("humidity");

// set up 'humidifier' and 'blind' feeds for recieving data
AdafruitIO_Feed *humidifier = io.feed("humidifier")
AdafruitIO_Feed *blind = io.feed("blind")

void setup() {

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // initialize dht22
  dht.begin();

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();
  
  humidifier->onMessage(handleHumidifier);
  blind->onMessage(handleBlinds);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

// message handler for humidifier
void handleHumidifier(AdafruitIO_data *data){
  Serial.print("received signal for humidfier -> ")
  if(data-toPinLevel() == HIGH){
    Serial.println("ON");
  }
  else{
    Serial.println("OFF");
  }

  // add code to write data to pin humidifier is connected to
  // needs testing to see how long on is optimal to change humidity

}

// message handler for blinds
void handleBlinds(AdafruitIO_data *data){
  Serial.print("Received signal for blind -> ")
  if(data->toPinLevel() == HIGH){
    Serial.println("OPEN");
  }
  else{
    Serial.println("CLOSED")
  }

  // add code to write data to pin blind is connected to
  
}

void loop() {
  io.run();

  sensors_event_t event;
  
  // Get temp event from DHT sensor
  dht.temperature().getEvent(&event);
  
  // Value to store the temp. DHT records in celsius
  float celsius = event.temperature;

  // Print value being sent to adafruit to serial monitor
  Serial.print("celsius: ");
  Serial.print(celsius);
  Serial.println("C");

  // save temp to Adafruit IO
  temperature->save(celsius);
 
  // Get humidity event from DHT sensor
  dht.humidity().getEvent(&event);

  // Value to store humidity
  int humidity = event.relative

  Serial.print("humidity: ");
  Serial.print(event.relative_humidity);
  Serial.println("%");

  // save humidity to Adafruit IO
  humidity->save(event.relative_humidity);

  // Value to store reading from photocell
  int reading = analogRead(photocellPin);

  Serial.print("Photocell: ");
  Serial.print(reading)
  Serial.println("%")

  // save photocell reading to Adafruit IO
  photocell->save(reading);

  // sends data every 10 seconds
  delay(10000);

}
