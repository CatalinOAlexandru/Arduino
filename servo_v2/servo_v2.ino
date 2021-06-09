#include <SR04.h>
#include <Servo.h>
#define TRIG_PIN 12
#define ECHO_PIN 11

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

//int pos = 0;    
long sonic;
double angle;

void setup() {
  Serial.begin(9600);
  myservo1.attach(9); // left fingers
  myservo2.attach(6); // thumb
  myservo3.attach(5); // little right
  myservo4.attach(3); // right
}

void loop() {    
    //setOnTarget();
    //pull();
    //push();
    sonic = sr04.Distance(); // Will return the distance from the ultrasonic device to object
    Serial.print(sonic);
    Serial.println("cm");

    delay(250);

    if(sonic > 60){
          setOnTarget(180);
      }
    else{
        angle = 180.0 * (sonic/50.0);
        Serial.print("angle: ");
        Serial.println(angle);
        setOnTarget(angle);
    }
}

void setOnTarget(double pos){
    myservo1.write(pos); // left fingers
    myservo2.write(pos); // thumb
    myservo3.write(pos);   // middle finger
    myservo4.write(pos); // pointer?
}

void pull(long pos){
      myservo1.write(pos);
      myservo2.write(pos);
      myservo3.write(pos);
      myservo4.write(pos);                                  
}

void push(long pos){
      myservo1.write(pos);
      myservo2.write(pos);
      myservo3.write(pos);
      myservo4.write(pos);               
}
