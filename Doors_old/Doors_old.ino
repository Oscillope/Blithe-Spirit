// Blithe Spirit Special Effects
// Jason Rosenman 2013

#define M1p 8
#define M1n 11
#define M1PWM 9
#define M2p 12
#define M2n 13
#define M2PWM 10
#define BUTTON 2
#define SPEED 255
boolean closed;
int count;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(M1p, OUTPUT);
  pinMode(M1n, OUTPUT);
  pinMode(M1PWM, OUTPUT);
  pinMode(M2p, OUTPUT);
  pinMode(M2n, OUTPUT);
  pinMode(M2PWM, OUTPUT);
  closed = true;
}

void loop() {
  if(digitalRead(BUTTON) == LOW && closed) {
    count = 0;
    open();
    closed = false;
  }
  else if(!closed) {
    close();
    closed = true;
  }
  else stop();
}

void stop() {
  digitalWrite(M1PWM, LOW);
  digitalWrite(M2PWM, LOW);
}

void open() {
  analogWrite(M1PWM, SPEED);
  analogWrite(M2PWM, SPEED);
  digitalWrite(M1p, HIGH);
  digitalWrite(M1n, LOW);
  digitalWrite(M2p, LOW);
  digitalWrite(M2n, HIGH);
  while(digitalRead(BUTTON) == LOW) {
    delay(1);
    count++;
  }
  stop();
}

void close() {
  analogWrite(M1PWM, SPEED);
  analogWrite(M2PWM, SPEED);
  digitalWrite(M1p, LOW);
  digitalWrite(M1n, HIGH);
  digitalWrite(M2p, HIGH);
  digitalWrite(M2n, LOW);
  delay(count+2);
  stop();
}
