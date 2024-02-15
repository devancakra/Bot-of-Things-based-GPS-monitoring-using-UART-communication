#include <SoftwareSerial.h> // calls a library called SoftwareSerial.h
SoftwareSerial WemosSerial(12, 13); // D6 As RX, D7 As TX -> Wemos D1 Mini

String raw_data, location; // data with String type is used for GPS sensor purposes

// Method: setup
void setup() {
  Serial.begin(115200); // start serial communication internally
  WemosSerial.begin(115200); // start serial communication externally  
}

// Method: loop
void loop() {  
  gpssensor(); // calling the gpssensor method
}

// Method: gpssensor
void gpssensor(){
  while(!WemosSerial.available()){ Serial.println("Failed to get sensor data, system tries to reconnect communication !!"); } // serial communication with the Arduino Pro Micro board failed
  raw_data = ""; // this String data type is used to store location data
  while(WemosSerial.available() > 0){ // this loop is used to read the available location data from the serial object
    raw_data += char(WemosSerial.read()); // adds each sensor data reading into a data string named raw_data
  }  
  location = raw_data.c_str(); // location variable is used to store string conversion data from raw_data
  Serial.println("Retrieve serial data from Arduino Pro Micro board..."); // display data to the Wemos D1 Mini serial monitor
  delay(2000); // delay -> 2 second 
  Serial.println(location); // print location data on the serial monitor
  delay(1000); // delay -> 1 second 
}