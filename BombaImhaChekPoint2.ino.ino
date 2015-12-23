#include <SoftwareSerial.h>
#include <SoftwareServo.h>

SoftwareServo  myservo1, myservo2, myservo3, myservo4, myservo5, myservo6;

int bluetoothTx = 7;
int bluetoothRx = 8;

int motor1 = 12;
int motor2 = 13;
int motor3 = 4;
int motor4 = 5;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void setup()
{
  digitalWrite(motor1, OUTPUT);
  digitalWrite(motor2, OUTPUT);
  digitalWrite(motor3, OUTPUT);
  digitalWrite(motor4, OUTPUT);

  myservo1.attach(11);
  myservo2.attach(10);
  myservo3.attach(3);
  myservo4.attach(6);

  //Setup usb serial connection to computer

  digitalWrite(motor1 , LOW);
  digitalWrite(motor2 , LOW);
  digitalWrite(motor3 , LOW);
  digitalWrite(motor4, LOW);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  //Read from bluetooth and write to usb serial


  if (bluetooth.available() >= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 * 256) + servopos;
    Serial.println(realservo);

    if (realservo >= 1000 && realservo < 1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      myservo1.write(servo1);
      SoftwareServo ::refresh();


    }
    if (realservo >= 2000 && realservo < 2180) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      myservo2.write(servo2);
      SoftwareServo ::refresh();


    }
    if ( realservo >= 5200 && realservo < 5300)
    {
      myservo3.write(90);
      myservo4.write(120);
      SoftwareServo ::refresh();

    }

    if ( realservo >= 5000 && realservo < 5100)
    {
      myservo3.write(120);
      myservo4.write(90);
      SoftwareServo ::refresh();

    }

    // Motor harekeet Kodu Burada motorlara  hareket saglanir
    //Geri hareket
    if (realservo >= 4000 && realservo < 4010) {// Sol geri hareket
      digitalWrite(motor3 , HIGH);
      delay(50);
      digitalWrite(motor4, LOW);
      Serial.println(realservo);
      digitalWrite(motor2 , HIGH);// sag motor geri
      delay(50);
      digitalWrite(motor1 , LOW);
      Serial.println(realservo);
    }

    //Ileri  Hareket
    if (realservo >= 4400 && realservo < 4500) { // sol motor  ileri
      digitalWrite(motor3 , LOW);
      digitalWrite(motor4 , HIGH);
      Serial.println(realservo);
      // sag Ileri Hareket
      digitalWrite(motor1 , HIGH);
      digitalWrite(motor2, LOW);
      //Serial.println(realservo);
    }
    /////////////////////////////////
    if (realservo >= 4200 && realservo < 4300) { // saga donus
      digitalWrite(motor1 , HIGH);
      digitalWrite(motor2, LOW);
      digitalWrite(motor3 , HIGH);
      digitalWrite(motor4 , LOW);
      // Serial.println(realservo);
    }
    if (realservo >= 4050 && realservo < 4100) { // sola donus
      digitalWrite(motor3 , LOW);
      digitalWrite(motor4 , HIGH);
      digitalWrite(motor1 , LOW);
      digitalWrite(motor2, HIGH);
      // Serial.println(realservo);
    }

    /************************************/
    if (realservo >= 4600 && realservo < 4700) {
      digitalWrite(motor1 , LOW);
      digitalWrite(motor2 , LOW);
      digitalWrite(motor3 , LOW);
      digitalWrite(motor4 , LOW);
    }

  }
}
