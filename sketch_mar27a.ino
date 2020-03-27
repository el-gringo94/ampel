const int green = 9;
const int yellow = 10;
const int red = 11;

const int status = 13;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

void ampel(char c) {
  switch (c) {
    case 'g':
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(13, HIGH);
      break;

    case 'y':
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(13, HIGH);
      break;

    case 'z': // red and yellow (from red to green phase)
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(13, HIGH);
      break;

    case 'r':
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(13, HIGH);
      break;
  }
}

void go () {
  ampel('z');
  delay(1000);
  ampel('g');
  delay(5000);
}

void stop () {
  ampel('y');
  delay(3000);
  ampel('r');
  delay(5000);
}

void stopOrGo(char c){
  switch(c){
    case 'g':
    go();
    break;

    case 's':
    stop();
    break;
  }
}

void loop() {
  if(Serial.available() > 0){
    char in = Serial.read();
    stopOrGo(in);
  }
}
