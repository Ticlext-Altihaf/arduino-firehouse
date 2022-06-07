#include <Servo.h>
// the setup function runs once when yu press reset or power the board
//4 = 1
//5 = 2
//13 = 3
//12 = 4


//MOTOR CONTROLLER
int IN_1 = 4, IN_2 = 5, IN_3 = 13, IN_4 = 12;
int ENA = 3, ENB = 11;

//FIREHOSE CONTROLELR
Servo myservo;
int pos = 0;
const int SERVO_FIREHOSE_PIN = 2;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  myservo.attach(SERVO_FIREHOSE_PIN);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  /*
     Servo loo
    for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    }
  */

  /*
   * 
  analogWrite(ENA, 100); //ENA pin
  analogWrite(ENB, 200); //ENB pin
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  delay(1000);

  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  delay(1000);
  */
}


void move(
