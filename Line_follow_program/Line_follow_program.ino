#define SERVO_PIN_ONE 9
#define SERVO_PIN_TWO 10
#define SERVO_POSITION_ONE 1000
#define SERVO_POSITION_TWO 2000
#define IR_SENSOR_ANALOG_PIN 0
#define PIVOT 200

int val = 0;   
boolean leftBool = true;
boolean rightBool = true; 

void setup() {
  Serial.begin(9600); 
  pinMode(SERVO_PIN_ONE, OUTPUT);
  pinMode(SERVO_PIN_TWO, OUTPUT);
  Serial.begin(9600);  
}

void loop() {  
  val = analogRead(IR_SENSOR_ANALOG_PIN); 
  if(val > PIVOT) {
    Forward(1);
  } else {
    if(rightBool) {
       RightRotate(1);
       rightBool = false;
       val = analogRead(IR_SENSOR_ANALOG_PIN);
       if(val < PIVOT) {
         RightRotate(1);
       }
    } else {
      LeftRotate(2);
      rightBool = true;
      val = analogRead(IR_SENSOR_ANALOG_PIN);
      if(val < PIVOT) {
         LeftRotate(2);
      }
    }
  }
  Serial.println(val);       
  delay(100);    
}

void Forward(int tick) {
  int i = 0;
   while(i < tick) {
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

void RightRotate(int tick) {
   int i = 0;
   while(i < tick) {
    digitalWrite(SERVO_PIN_ONE, HIGH);
    digitalWrite(SERVO_PIN_TWO, HIGH);
    delayMicroseconds(SERVO_POSITION_TWO); 
    digitalWrite(SERVO_PIN_TWO, LOW);
    digitalWrite(SERVO_PIN_ONE, LOW);
    delay(30);
    i++;
  }
}

void LeftRotate(int tick) {
    int i = 0;
    while(i < tick) {
    digitalWrite(SERVO_PIN_ONE, HIGH);
    digitalWrite(SERVO_PIN_TWO, HIGH);
    delayMicroseconds(SERVO_POSITION_ONE);
    digitalWrite(SERVO_PIN_ONE, LOW);
    digitalWrite(SERVO_PIN_TWO, LOW);
    delay(30);
    i++;
  } 
}


