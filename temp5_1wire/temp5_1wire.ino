// This Arduino sketch reads DS18B20 "1-Wire" digital
// temperature sensors.
// Tutorial:
// http://www.hacktronics.com/Tutorials/arduino-1-wire-tutorial.html

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 3 on the Arduino
#define ONE_WIRE_BUS 16

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// Assign the addresses of your 1-Wire temp sensors.
// See the tutorial on how to obtain these addresses:
// http://www.hacktronics.com/Tutorials/arduino-1-wire-address-finder.html

DeviceAddress insideThermometer1 = { 0x28, 0x64, 0x8E, 0x34, 0x05, 0x00, 0x00, 0x1B };
DeviceAddress insideThermometer2 = { 0x28, 0x62, 0xBF, 0x34, 0x05, 0x00, 0x00, 0xE0 };
DeviceAddress insideThermometer3 = { 0x28, 0xFA, 0xCC, 0x35, 0x05, 0x00, 0x00, 0x5C };
DeviceAddress insideThermometer4 = { 0x28, 0xB5, 0xF4, 0x34, 0x05, 0x00, 0x00, 0x38 };
DeviceAddress insideThermometer5 = { 0x28, 0x43, 0x86, 0x35, 0x05, 0x00, 0x00, 0x99 };

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  // Start up the library
  sensors.begin();
  // set the resolution to 10 bit (good enough?)
  sensors.setResolution(insideThermometer1, 12);
  sensors.setResolution(insideThermometer2, 12);
  sensors.setResolution(insideThermometer3, 12);
  sensors.setResolution(insideThermometer4, 12);
  sensors.setResolution(insideThermometer5, 12);
        
}

void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  if (tempC == -127.00) {
    Serial.print("Error getting temperature");
  } else {
    Serial.print("C: ");
    Serial.print(tempC);
    Serial.print(" F: ");
    Serial.print(DallasTemperature::toFahrenheit(tempC));
  }
}

void loop(void)
{ 
  delay(2000);
  Serial.print("Getting temperatures...\n\r");
  sensors.requestTemperatures();
  
  Serial.print("Temp1: ");
  printTemperature(insideThermometer1);
  Serial.print("\n\r");
   Serial.print("Temp2: ");
  printTemperature(insideThermometer2);
  Serial.print("\n\r");
   Serial.print("Temp3: ");
  printTemperature(insideThermometer3);
  
  Serial.print("Temp4: ");
  printTemperature(insideThermometer4);
  Serial.print("\n\r");
  
  Serial.print("Temp5: ");
  printTemperature(insideThermometer5);


  Serial.print("\n\r\n\r");
  
}

