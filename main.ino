#include <Servo.h>


//ADDR:98D3:41:F65D29


//MOTOR CONTROLLER
const int IN_1 = 4, IN_2 = 5, IN_3 = 13, IN_4 = 12;
int ENA = 3, ENB = 11;

//FIREHOSE CONTROLELR
Servo myservo;
int pos = 0;
const int SERVO_FIREHOSE_PIN = 2;
const int SERVO_MIN = 45, SERVO_MAX = 140;
//Heat Sensor
const int HEAT_SENSOR_PIN_1 = 7, HEAT_SENSOR_PIN_2 = 7;
int HEAT_SENSOR_VALUE_1 = 0, HEAT_SENSOR_VALUE_2 = 0;

//Pump Relay
const int PUMP_RELAY_PIN = 8;

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
  pinMode(PUMP_RELAY_PIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  /*
    digitalWrite(PUMP_RELAY_PIN, HIGH);
    delay(5000);
    digitalWrite(PUMP_RELAY_PIN, LOW);
    delay(5000);
  */
  /*
    HEAT_SENSOR_VALUE_1 = analogRead(HEAT_SENSOR_PIN_1);
    HEAT_SENSOR_VALUE_2 = analogRead(HEAT_SENSOR_PIN_2);
    Serial.print("TEMPRATURE_1:");
    Serial.println(HEAT_SENSOR_VALUE_1);
    Serial.print("TEMPRATURE_2:");
    Serial.println(HEAT_SENSOR_VALUE_2);
  */

  //Servo loo
  for (pos = SERVO_MIN; pos <= SERVO_MAX; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = SERVO_MAX; pos >= SERVO_MIN; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }


  /*

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


  int count = 0;
  for (count = 1; count < 3; count += 1) {
    move(count, 1);

    Serial.println(count);
    delay(1000);
  }

}


//1 = MUNDUR KIRI
//2 = MAJU KIRI
//3 = MUNDUR KANAN
//4 = MAJU KANAN

bool forward[] = {LOW, HIGH, LOW, HIGH}, backward[] = {HIGH, LOW, HIGH, LOW};
bool left[] = {LOW, LOW, LOW, LOW}, right[] = {LOW, LOW, LOW, LOW};
bool stay[] = {LOW, LOW, LOW, LOW};
//bool keked[] = {HIGH, LOW, HIGH, LOW};


void move(int direction, float force) {
  //Controlling speed (0 = off and 255 = max speed)
  int theForce = force * 255;
  analogWrite(ENA, theForce); //ENA pin
  analogWrite(ENB, theForce); //ENB pin

  bool *keked;
  if (direction == 1) {
    keked = forward;
  }
  if (direction == 3) {
    keked = left;
  }
  if (direction == 2) {
    keked = backward;
  }
  if (direction == 4) {
    keked = right;
  }
  /*
  digitalWrite(IN_1, keked[0]);
  digitalWrite(IN_2, keked[1]);
  digitalWrite(IN_3, keked[2]);
  digitalWrite(IN_4, keked[3]);
  */
  bool b1 = random(1, 3) == 1;
  bool b2 = random(1, 3) == 1;
  Serial.print("b1:");
  Serial.println(b1);
  Serial.print("b2:");
  Serial.println(b2);

  //if (direction == 1) {
  digitalWrite(IN_1, b1 ? LOW : HIGH);
  digitalWrite(IN_2, b1 ? HIGH : LOW);
  digitalWrite(IN_3, b2 ? LOW : HIGH);
  digitalWrite(IN_4, b2 ? HIGH : LOW);
  //}
 
}
