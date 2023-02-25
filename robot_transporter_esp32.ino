/*************************************
   Connected pin:
   Nama           ESP32
   Driver Motor   32,33,25,26
   Servo          18
 *************************************/
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


#include <ESP32Servo.h>

// create four servo objects 
Servo servo1;

int minUs = 1000;
int maxUs = 2000;
int servo1Pin = 18;


int pos = 0;      // position in degrees
ESP32PWM pwm;

int IN1 = 32;
int IN2 = 33;
int IN3 = 25;
int IN4 = 26;

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  servo1.setPeriodHertz(50);      // Standard 50hz servo

  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println("Enter number for control option:");
  Serial.println("1. FORWARD");
  Serial.println("2. REVERSE");
  Serial.println("3. STOP");
  Serial.println();
}

void loop()
{
  char user_input;

  while (SerialBT.available())
  {
    user_input = SerialBT.read();
//    digitalWrite(IN1, LOW); //OFF
//    digitalWrite(IN2, LOW);

    if (user_input == 'F')
    {
      Forward();
    }
    else if (user_input == 'B')
    {
      Reverse();
    }
        else if (user_input == 'L')
    {
      kanan();
    }
        else if (user_input == 'R')
    {
      kiri();
    }
    else if (user_input == 'S')
    {
      Stop();
    }
    else if (user_input == 'w')
    {
      Servo1();
    }
    else if (user_input == 'W')
    {
      Servo2();
    }
    else
    {
      Serial.println("Invalid option entered.");
    }
  }
}


void Forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  Serial.print("Motor 1 Forward");
  Serial.println();

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Motor 2 Forward");
  Serial.println();
}

void Reverse()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  Serial.print("Motor 2 Reverse");
  Serial.println();

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Motor 2 Reverse");
  Serial.println();
}

void Stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  Serial.print("Motor 1 Stop");
  Serial.println();

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Motor 2 Stop");
  Serial.println();

}

void kanan()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  Serial.print("Motor 1 Forward");
  Serial.println();

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Motor 2 Stop");
  Serial.println();

}

void kiri()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  Serial.print("Motor 1  Stop");
  Serial.println();

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Motor 2 Forward");
  Serial.println();

}

void Servo1 (){
  servo1.attach(servo1Pin, minUs, maxUs);
  for (pos = 0; pos < 270; pos += 1) { // sweep from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);
    delay(1);             // waits 20ms for the servo to reach the position
  }
 }

void Servo2 (){
  servo1.attach(servo1Pin, minUs, maxUs);
  for (pos = 2700; pos > 1; pos -= 1) { // sweep from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);
    delay(1);             // waits 20ms for the servo to reach the position
  }
 }
