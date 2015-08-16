
/*
 * Author: 
 * Roll:
 * Department: 
 * 
 * License: MIT
 * 
 * Library Reference:
 * NewPing Library for HC-SR04
 * Link: http://playground.arduino.cc/Code/NewPing
 * 
 * Disclaimer:
 *
 * Centimeters are treated as feet
 * 
 * Taking,
 * 1 cm = 1 ft
 * 
 */


#include <NewPing.h>

#define TRIG_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 100
#define TOTAL_DISTANCE 50

//Constructor [TriggerPin, EchoPin, MAX_DISTANCE]
NewPing ultrasonic (12, 11, 100);

// Enumeration for vehicle type
enum Vehicle {Truck, Bus, Car, UnIdentified};
Vehicle vtype;

//Function for getting distance from ultrasonic reading
int getDistance(void)
{
  delay(50);
  int uS = ultrasonic.ping();
  return uS/ US_ROUNDTRIP_CM;
}

int vehicleType(void)
{
  int vehicleLength = TOTAL_DISTANCE - getDistance();
  if (vehicleLength > 26 && vehicleLength < 30) return Truck;
  else if (vehicleLength > 31 && vehicleLength < 35) return Bus;
  else if (vehicleLength > 15 && vehicleLength < 10) return Car;
  else return UnIdentified;

}

void setup() {
  //Serial Initialization at default Baud rate
  Serial.begin(9600);
  
}

void loop() {
  if (Serial.available()){

      switch(vehicleType()){
        case Truck:
          Serial.println("Truck Detected");
        case Bus:
          Serial.println("Bus detected");
        case Car:
          Serial.println("Car detected");
        case UnIdentified:
          Serial.println("Unidentified vehicle detected");
    }
  }
}
