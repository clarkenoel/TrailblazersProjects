int buttonPin = 19;
int redLED = 18;
int segA = 4;
int segB = 5;
int segC = 6;
int segD = 7;
int segE = 8;
int segF = 3;
int segG = 2;
int dipBit3 = 9;
int dipBit2 = 10;
int dipBit1 = 11;
int dipBit0 = 12;
int greenLED = 13;


void setup() {
  pinMode(segA,OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(greenLED,OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(dipBit3, INPUT_PULLUP);
  pinMode(dipBit2, INPUT_PULLUP);
  pinMode(dipBit1, INPUT_PULLUP);
  pinMode(dipBit0, INPUT_PULLUP);

  randomSeed(analogRead(A0));
}

int read_4_bit() {
  int b3 = digitalRead(dipBit3);
  int b2 = digitalRead(dipBit2);
  int b1 = digitalRead(dipBit1);
  int b0 = digitalRead(dipBit0);

  //IDK WHY

  int value = (b3 << 3) | (b2 << 2) | (b1 << 1) | b0;
  return value;
  }

void baseten_to_seven(int num) {

  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);

  if (num == 0 ) {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  }
  else if (num == 1) {
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  }
  else if (num == 2) {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segG, HIGH);
  }
  else if (num == 3) {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segG, HIGH);
  }
  else if (num == 4) {
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  }
  else if (num == 5) {
  digitalWrite(segA, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  }
  else if (num == 6) {
  digitalWrite(segA, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  }
  else if (num == 7) {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  }
  else if (num == 8) {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  }
  else if (num == 9) {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  }

  return num ;
}

void loop() {
  // put your main code here, to run repeatedly:
  static bool prevButton = HIGH;
  bool currButton = digitalRead(buttonPin);

  // Detect Button Press
  if (prevButton == HIGH && currButton == LOW) {
  delay(50); //this is the debounce
  if(digitalRead(buttonPin)== LOW) {
  int roll = random(0, 9); // random number from 1 to 6
  baseten_to_seven(roll); // show it
  int dipValue = read_4_bit(); //read th eDIP switch

  if (dipValue == roll) {
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
 }
  //compare and control LEDs
  if (dipValue!= roll) {
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  }

  delay(250);
  }
  }
  prevButton = currButton;
}
