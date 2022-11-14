/* Program By Teknologi Rekayasa Mekatronika
 * ------------Jurusan Teknik---------------
 * ------Politeknik Negeri Jember----------
 */
#include <Servo.h>

Servo myservo1;

int pos1 = 0;

int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
int enA = 3;
int enB = 11;
char val;

void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  myservo1.attach(12);
  myservo2.attach(13);
  Serial.begin(9600);
}
void loop() {
  while (Serial.available() > 0)
  {
    val = Serial.read();
    Serial.println(val);
  }
  if ( val == 'F') // Forward
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    analogWrite(enA,  200);
    analogWrite(enB,  200);
  }
  else if (val == 'B') // Backward

  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA,  200);
    analogWrite(enB,  200);
  }
  else if (val == 'L') //Left
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA,  200);
    analogWrite(enB,  200);
  }
  else if (val == 'R') //Right
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA,  255);
    analogWrite(enB,  255);
  }
  else if (val == 'S') //Stop
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA,  0);
    analogWrite(enB,  0);
  }
  else if (val == 'I') //Forward Right
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);

    digitalWrite(in4, LOW);
    analogWrite(enA,  255);
    analogWrite(enB,  255);
  }
  else if (val == 'J') //Backward Right
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA,  255);
    analogWrite(enB,  255);
  }
  else if (val == 'G') //Forward Left
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA,  255);
    analogWrite(enB,  255);
  }
  else if (val == 'H') //Backward Left
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA,  255);
    analogWrite(enB,  255);
  }
  if (val == 'w') {
    for (pos1 = 0; pos1 < 270; pos1 += 1)
    {
      myservo1.write(pos1);
    }
    delay(100);

  }
  if (val == 'W') {
    for (pos1 = 270; pos1 > 1; pos1 -= 1)
    {
      myservo1.write(pos1);
    }
    delay(100);

  }
}
