#include <Arduino.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  // put your setup code here, to run once:
  // put your main code here, to run repeatedly:
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.begin(9600);
  
}
  
void loop() {
  
  if (SerialBT.available()) {
      //Serial.println("received this:");
      //Serial.println(SerialBT.readString());

      //SerialBT.println("tak for beskeden - den blev jeg glad for?");
      //SerialBT.write(13); // "\n"

      //sending fake pulse measurement
      SerialBT.println(179);
      delay(1000);
  }
}
