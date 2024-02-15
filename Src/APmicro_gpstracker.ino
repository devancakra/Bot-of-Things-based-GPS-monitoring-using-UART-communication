float lattitude, longitude; // data with float type is used for GPS sensor purposes

// Method: setup
void setup() {
  Serial.begin(9600); // start serial communication internally
  Serial1.begin(115200); // start serial communication externally 
}

// Method: loop
void loop() {  
  sensor(); // calling the sensor method
  internal_data(); // calling the internal_data method
  external_data(); // calling the external_data method
}

// Method: sensor
void sensor(){
  // dummy Data
  lattitude = -3.621248;
  longitude = 98.815738;
}

// Method: internal_data
void internal_data(){
  // display data to the Arduino Pro Micro serial monitor
  Serial.println("Transmit serial data to Wemos D1 Mini...");
  delay(1000); // delay -> 1 second
  Serial.println("lattitude : "+String(lattitude,6));
  Serial.println("longitude : "+String(longitude,6));
  delay(1000); // delay -> 1 second
}

// Method: external_data
void external_data(){
  // send data from Arduino Pro Micro to Wemos D1 Mini
  Serial1.print(String(lattitude,6));
  Serial1.print(String(longitude,6));
  delay(1000); // delay -> 1 second
}
