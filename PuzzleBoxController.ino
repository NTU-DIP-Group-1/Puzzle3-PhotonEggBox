int led = D7;
int pin1 = D0;
int pin2 = D1;
int pin3 = D2;

int pos = 0;
Servo myservo;

void setup()
{

   pinMode(led, OUTPUT);

   Particle.function("servo",servoToggle);

   digitalWrite(led, LOW);

}

void loop()
{
  delay(1);
}


int servoToggle(String servoNum) {

    int currPin;

    if (servoNum == "1") {
        currPin = pin1;
    } else if (servoNum == "2") {
        currPin = pin2;
    } else {
        currPin = pin3;
    }

    myservo.attach(currPin);

    for(pos = 90; pos>=0; pos-=1) {
        myservo.write(pos);
        delay(15);
    }

    delay(1000);

     for(pos = 0; pos < 90; pos += 1) {
        myservo.write(pos);
        delay(15);
    }

    myservo.detach();

    return 1;
}
