#include <NewPing.h>
#define ECHO_PIN 8
#define TRIG_PIN 7
#define MAX_DISTANCE 200 
#define MIN_DISTANCE 20

#define N 15
#define SERVO_PIN_ONE 9
#define SERVO_PIN_TWO 10
#define SERVO_POSITION_ONE 1000
#define SERVO_POSITION_TWO 2000

int actual_distance = 0;

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600); 
  pinMode(SERVO_PIN_ONE, OUTPUT);
  pinMode(SERVO_PIN_TWO, OUTPUT);
  Serial.begin(9600);  
}

void loop() {  
  actual_distance = sonar.ping_cm();
  Serial.println(actual_distance);
  if(actual_distance <= MIN_DISTANCE) {
     RightRotate();
     delay(1500);
  } else {
     Forward();
     delay(1500);
  }
  delay(100);
}

void Forward() {
  int i = 0;
   while(i < N) {
    digitalWrite(SERVO_PIN_ONE, HIGH);
    delayMicroseconds(SERVO_POSITION_ONE); 
    digitalWrite(SERVO_PIN_ONE, LOW);
    digitalWrite(SERVO_PIN_TWO, HIGH);
    delayMicroseconds(SERVO_POSITION_TWO);
    digitalWrite(SERVO_PIN_TWO, LOW);
    delay(30);
    i++;
  }
}

void RightRotate() {
   int i = 0;
   while(i < N) {
    digitalWrite(SERVO_PIN_ONE, HIGH);
    digitalWrite(SERVO_PIN_TWO, HIGH);
    delayMicroseconds(SERVO_POSITION_TWO); 
    digitalWrite(SERVO_PIN_TWO, LOW);
    digitalWrite(SERVO_PIN_ONE, LOW);
    delay(30);
    i++;
  }
}

/*void Backward() {
  int i = 0;
   while(i < N) {
    digitalWrite(SERVO_PIN_ONE, HIGH);
    delayMicroseconds(SERVO_POSITION_TWO); 
    digitalWrite(SERVO_PIN_ONE, LOW);
    digitalWrite(SERVO_PIN_TWO, HIGH);
    delayMicroseconds(SERVO_POSITION_ONE); 
    digitalWrite(SERVO_PIN_TWO, LOW);
    delay(30);
    i++;
  }
}

void LeftRotate() {
    int i = 0;
    while(i < N) {
    digitalWrite(SERVO_PIN_ONE, HIGH);
    digitalWrite(SERVO_PIN_TWO, HIGH);
    delayMicroseconds(SERVO_POSITION_ONE);
    digitalWrite(SERVO_PIN_ONE, LOW);
    digitalWrite(SERVO_PIN_TWO, LOW);
    delay(30);
    i++;
  } 
}*/


