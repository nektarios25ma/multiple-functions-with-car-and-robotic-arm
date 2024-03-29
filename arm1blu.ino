/*
 gel soudas 
 Teacher Nektarios KOURAKIS
 STUDENTS: SPYROS, MANOLIS
*/
#include <Servo.h>  //add the library of servo
Servo myservo1; //define the name of servo variable
Servo myservo2; //define the name of servo variable
Servo myservo3; //define the name of servo variable
Servo myservo4; //define the name of servo variable
int error = 0;
byte vibrate = 0;
int pos1 = 90, pos2 = 100, pos3 = 80, pos4 = 80; // define angle variable of four servos and set initial value(posture angle value when setting up)
char blue_val;
int M1[20];          //define four arrays 
int M2[20];          //respectively save the angle of four servos
int M3[20];          //the array length is 20, can save 0~20 angle data
int M4[20];
int i = 0, j = 0, t = 0; //i is used to save array，j is used to save the maximum value of i,t is used to exit while loop
const int AIN2 = 2; //define the driving pins of motor
const int PWMA = 3;
const int BIN2 = 4; //when AIN2 is low and AIN1 is high, BIN2 is high and BIN1 is low
const int PWMB = 5;
int echoPin = A3; // ultrasonic module   ECHO to A3
int trigPin = A4; // ultrasonic module   TRIG to A4
int speeds = 100; // set the initial value of rotation speed of motor
int ledPin1 = 6; // Define the LED pin at D6
int ledPin2 = 7; // Define the LED pin at D7
int Ultrasonic_Ranging() { //ultrasonic ranging function
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  //send least 10us high level to trig pin to trigger ultrasonic waves 
  digitalWrite(trigPin, LOW);
  int distance = pulseIn(echoPin, HIGH);  // reading the duration of high level
  distance = distance / 58; // Transform pulse time to distance
  delay(30);
  return distance;    //return distance to this function
}
void setup() {
  Serial.begin(9600);    //set to baud rate to 57600 when printing ps2, however, Bluetooth can't be used
  myservo1.attach(A1);  //set control pin of servo 1 to A1
  myservo2.attach(A0);  //set control pin of servo 2 to A0
  myservo3.attach(8);   //set control pin of servo 3 to D8
  myservo4.attach(9);   //set control pin of servo 4 to D9
  myservo3.write(pos3);  //servo 3 rotates to 80° 
  delay(500);
  myservo2.write(pos2);  //servo 2 rotates to 100° 
  delay(500);
  myservo1.write(pos1);  //servo 1 rotates to 90°
  delay(500);
  myservo4.write(pos4);  //servo 4 rotates to 90° 
  pinMode(2, OUTPUT); //set ports of motor to output
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode (ledPin1, OUTPUT); // initialize ledpin1 as an output
  pinMode (ledPin2, OUTPUT); // initialize ledpin1 as an output
  pinMode(echoPin, INPUT); //set echoPin to input
  pinMode(trigPin, OUTPUT); //set trigPin to output
  
}

void loop() {
 int analogValue = analogRead(A5);
  if (analogValue < 600) {
 //   Serial.println(" - Light");
     analogWrite (ledPin1, 1022);
     analogWrite (ledPin2, 1022);
  } 
else{ analogWrite (ledPin1, 0);
  analogWrite (ledPin2, 0);}


  if (Serial.available() > 0) { //determine if Bluetooth receives signals
    blue_val = Serial.read();
    Serial.println(blue_val);
    switch (blue_val) {
      case 'F': advance(); break; //receive‘F’ to go forward
      case 'B': back();   break;  //receive‘B’ to go back

      case 'L': turnL();  break;  //receive‘L’ to turn left

      case 'R': turnR();  break;  //receive‘R’ to turn right

      case 'S': stopp();  break;  //receive‘S’ to stop

      case 'a': speeds_a(); break;  //receive‘a’, car speeds up

      case 'd': speeds_d(); break; //receive‘d’, car speeds down

      case 'Q': LF();     break;  //smaller arm lifts up

      case 'E': LB();     break;  //smaller arm lifts down

      case 'l': T_left(); break;  //arm turns left

      case 'r': T_right(); break; //arm turns right
      
      case 'f': RF();     break;  //bigger swings forward
      
      case 'b': RB();     break;  //bigger arm swings back      
      case 'V': ZK();     break;  //claw opens
      
      case 'P': ZB();     break;  //claw closes
      
      case 't': read_servo(); break;  //receive‘t’, remember the motion
      
      case 'i': do_servo(); break;
      
      case 'Y': avoid(); break; //receive‘Y’ to enable obstacle avoidance mode      
      case 'U': follow(); break; //receive‘U’ to enable ultrasonic follow mode      
      default: break;
    }
  }
  
  //memory();  //call the memory function 
  
  delay(10);
}

void speeds_a() {
  int a_flag = 1;
  while (a_flag) {
    Serial.println(speeds);
    if (speeds <= 254) { //maximize to add 255
      speeds++;
      delay(10); //change delayed time to alter the acceleration of car
    }
    blue_val = Serial.read();
    if (blue_val == 'S') a_flag = 0;  //receive‘S’ to stop speeding up
  }
}

void speeds_d() {
  int d_flag = 1;
  while (d_flag) {
    Serial.println(speeds);
    if (speeds >= 1) { //minimize to 0
      speeds--;
      delay(10);  //change delayed time to alter the deacceleration of car
    }
    blue_val = Serial.read();
    if (blue_val == 'S') d_flag = 0; //receive‘S’ to stop speeding down
  }
}

void T_left() { //turn left
  int left_flag = 1;
  while (left_flag) {
    pos1 += 1;
    myservo1.write(pos1);
    delay(8);
    if (pos1 > 180) { // set the limited angle value of servo
      pos1 = 180;
    }
    blue_val = Serial.read();
    if (blue_val == 's')left_flag = 0;
  }
}

void T_right() { //turn right
  int right_flag = 1;
  while (right_flag) {
    pos1 -= 1;
    myservo1.write(pos1);
    delay(8);
    if (pos1 < 0) {
      pos1 = 0;
    }
    blue_val = Serial.read();
    if (blue_val == 's')right_flag = 0;
  }
}

void ZB() { //claw closes
  int ZB_flag = 1;
  while (ZB_flag) {
    pos4 -= 2;
    myservo4.write(pos4);
    delay(8);
    if (pos4 <= 85) {
      pos4 = 85;
    }
    blue_val = Serial.read();
    if (blue_val == 's')ZB_flag = 0;
  }
}

void ZK() { //claw opens
  int ZK_flag = 1;
  while (ZK_flag) {
    pos4 += 2;
    myservo4.write(pos4);
    delay(8);
    if (pos4 >= 180) {
      pos4 = 180;
    }
    blue_val = Serial.read();
    if (blue_val == 's')ZK_flag = 0;
  }
}

void LF() { //smaller arm lifts up
  int LF_flag = 1;
  while (LF_flag) {
    pos2 += 1;
    myservo2.write(pos2);
    delay(8);
    if (pos2 >= 100) {
      pos2 = 100;
    }
    blue_val = Serial.read();
    if (blue_val == 's')LF_flag = 0;
  }
}

void LB() { //smaller arm lifts down
  int LB_flag = 1;
  while (LB_flag) {
    pos2 -= 1;
    myservo2.write(pos2);
    delay(8);
    if (pos2 <= 1) {
      pos2 = 0;
    }
    blue_val = Serial.read();
    if (blue_val == 's')LB_flag = 0;
  }
}
void RF() { // bigger arm swings forward
  int RF_flag = 1;
  while (RF_flag) {
    pos3 += 1;
    myservo3.write(pos3);
    delay(8);
    if (pos3 >= 180) {
      pos3 = 180;
    }
    blue_val = Serial.read();
    if (blue_val == 's')RF_flag = 0;
  }
}
void RB() { // bigger arm swings back
  int RB_flag = 1;
  while (RB_flag) {
    pos3 -= 1;
    myservo3.write(pos3);
    delay(8);
    if (pos3 <= 80) {
      pos3 = 80;
    }
    blue_val = Serial.read();
    if (blue_val == 's')RB_flag = 0;
  }
}
void read_servo() {
  M1[i] = myservo1.read(); //save the current servo angles in array
  delay(100); //delay time to save angle value
  M2[i] = myservo2.read();
  delay(100);
  M3[i] = myservo3.read();
  delay(100);
  M4[i] = myservo4.read();
  delay(100);
  i++;  ///i increases 1 when save each time
  j = i; // set the value of i to j
  //  if(i>20)i=19;
  delay(200);
}
void do_servo() {
  i = 0; //i clears
  t = 1; //used for while loop
  pos1 = myservo1.read(); //read the current value and set to pos
  pos2 = myservo2.read();
  pos3 = myservo3.read();
  pos4 = myservo4.read();
  while (t) {
    for (int k = 0; k < j; k++) { //loop j times, execute all saved motions
      if (pos1 < M1[k]) { //when the angle value of servo 1 is more than the value saved in array 1  
        while (pos1 < M1[k]) { //while loop，make servo rotate to value where the array is saved
          myservo1.write(pos1); //servo 1 executes posture
          pos1++;   //pos1 increases 1
          delay(8); //delay in 8ms to control rotation speed of servo
        }
      }
      else {  //when the angle of servo 1 is more than the value saved in array 1
        while (pos1 > M1[k]) { //while loop, make servo rotate to value where the array is saved
          myservo1.write(pos1); //servo 1 executes posture
          pos1--;   //pos1 reduces 1
          delay(8); //delay in 8ms to control rotation speed of servo
        }
      }
      
      if (pos2 < M2[k]) {
        while (pos2 < M2[k]) {
          myservo2.write(pos2);
          pos2++;
          delay(8);
        }
      }
      else {
        while (pos2 > M2[k]) {
          myservo2.write(pos2);
          pos2--;
          delay(8);
        }
      }

      if (pos3 < M3[k]) {
        while (pos3 < M3[k]) {
          myservo3.write(pos3);
          pos3++;
          delay(8);
        }
      }
      else {
        while (pos3 > M3[k]) {
          myservo3.write(pos3);
          pos3--;
          delay(8);
        }
      }

      if (pos4 < M4[k]) {
        while (pos4 < M4[k]) {
          myservo4.write(pos4);
          pos4++;
          delay(8);
        }
      }
      else {
        while (pos4 > M4[k]) {
          myservo4.write(pos4);
          pos4--;
          delay(8);
        }
      }
    }
    if (Serial.available() > 0) { //exit loop
      if (Serial.read() == 't') { //receive‘i’ and‘t’
        t = 0; //set t to 0，exit while loop
        break;  //exit
      }
    }
  }
}

void avoid() { //ultrasonic obstacle avoidance
  int avoid_flag = 1;
  while (avoid_flag) {
    int distance = Ultrasonic_Ranging();
    Serial.print("distance=");
    Serial.println(distance);
    if (distance < 30 && distance > 2) { //when distance is less than 30cm
      if (distance < 18) { //when distance is less than 18, go back
        back();
        delay(300);
      }
      else { //when the distance is more than 18 and less than 30，turn right
        turnR();
        delay(300);
      }
    }
    else {  //when distance is more than 30, go forward
      advance();
    }
    blue_val = Serial.read();
    if (blue_val == 'S'){
      stopp();
      avoid_flag = 0;
    }
  }
}

void follow() {   //ultrasonic follow
  int follow_flag = 1;
  while (follow_flag) {
    int distance = Ultrasonic_Ranging();
    Serial.print("distance=");
    Serial.println(distance);
    if (distance < 40 && distance > 2) { //if 2<distance <40
      if (distance < 20) { //if distance < 20，go back
        if (distance < 15) {
          back();
        }
        else {
          stopp();
        }
      }
      else { //if 20<distance<35, go forward 
        advance();
      }
    }
    else {  //if distance>35 or distance<2, stop
      stopp();
    }
    blue_val = Serial.read();
    if (blue_val == 'S'){
      stopp();
      follow_flag = 0;
    }
  }
}



void advance() {   //go forward
  digitalWrite(AIN2, LOW); //when AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA, speeds); //rotation speed of motor MA is speeds
  digitalWrite(BIN2, HIGH); //When BIN2 is high and BIN1 is low, motor MB turns clockwise
  analogWrite(PWMB, speeds); //rotation speed of motor MB is speeds
}
void turnL() {  //turn left
  digitalWrite(AIN2, HIGH); //when AIN2 is high and AIN1 is low，motor MA turns anticlockwise
  analogWrite(PWMA, speeds); //rotation speed of motor MA is speeds
  digitalWrite(BIN2, HIGH); //When BIN2 is high and BIN1 is low, motor MB turns clockwise
  analogWrite(PWMB, speeds); //rotation speed of motor MB is speeds
}
void turnR() {  //turn right
  digitalWrite(AIN2, LOW); //when AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA, speeds); //rotation speed of motor MA is speeds
  digitalWrite(BIN2, LOW); //When BIN2 is low and BIN1 is high, motor MB turns clockwise
  analogWrite(PWMB, speeds); //rotation speed of motor MB is speeds, the same below
}
void back() {   //go back  
  digitalWrite(BIN2, LOW); //When BIN2 is low and BIN1 is high motor MB turns anticlockwise
  analogWrite(PWMB, speeds); ///rotation speed of motor MB is speeds, the same below  
  digitalWrite(AIN2, HIGH); //when AIN2 is high and AIN1 is low，motor MA turns anticlockwise
  analogWrite(PWMA, speeds); //rotation speed of motor MA is speeds
}
void stopp() {  //stop
  analogWrite(PWMA, 0); //rotation speed of motor MA is 0
  analogWrite(PWMB, 0); //rotation speed of motor MB is 0
}
