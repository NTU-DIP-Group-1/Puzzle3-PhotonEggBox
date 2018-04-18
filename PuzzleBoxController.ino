int pin1 = D0;
int pin2 = D1;
int pin3 = WKP;

int pos = 0;
Servo myservo; 

void setup()
{
    Particle.function("servo",servoToggle);
    Particle.function("reset_servo",reset_servo);
    
    reset_servo("");
}

void loop()
{

}


int servoToggle(String servoNum) {
    
    int currPin;
    
    if (servoNum == "1") {
        currPin = pin1;
    } else if (servoNum == "2") {
        currPin = pin2;
    } else if (servoNum == "3"){
        currPin = pin3;
    } else {
        return 0;
    }
    
    myservo.attach(currPin);
    delay(500);
    for (pos = 100; pos >= 0; pos -= 1) { 
        myservo.write(pos);             
        delay(30);
    }
    delay(1000);
    for (pos = 0; pos <= 100; pos += 1) { 
        myservo.write(pos);             
        delay(15);                     
    }   
    delay(1000);
    myservo.detach();
    
    return 1;
}

int reset_servo (String null){
    myservo.attach(pin1);
    for (pos = 0; pos <= 100; pos += 1) { 
            myservo.write(pos);         
            delay(15);
    }
    myservo.detach();
    delay(500);
    
    myservo.attach(pin2);
    for (pos = 0; pos <= 100; pos += 1) { 
            myservo.write(pos);              
            delay(15);
    }
    myservo.detach();
    delay(500);
   
    myservo.attach(pin3);
    for (pos = 0; pos <= 100; pos += 1) { 
            myservo.write(pos);            
            delay(15);
    }
    myservo.detach();
    delay(500);
}
