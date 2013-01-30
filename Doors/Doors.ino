// Blithe Spirit Special Effects
// Jason Rosenman 2013

#include <Servo.h>

#define BUTTON 2
#define SWITCH 3
#define CALSW 4
#define SPEED 255
#define L 1
#define R 2
Servo left;
Servo right;
int start;
boolean closed;
boolean cal;
int door = 1;
int count;
int buttonState = HIGH;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin
int switchState = HIGH;
int lastSwitchState = HIGH;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(SWITCH, INPUT_PULLUP);
  pinMode(CALSW, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  left.attach(9);
  right.attach(10);
  left.write(90);
  right.write(90);
  if(digitalRead(SWITCH) == LOW) {
    digitalWrite(13, HIGH);
    delay(250);
    digitalWrite(13, LOW);
    delay(250);
    digitalWrite(13, HIGH);
    delay(250);
    digitalWrite(13, LOW);
    delay(250);
    digitalWrite(13, HIGH);
    delay(250);
    digitalWrite(13, LOW);
    closed = true;
    if(digitalRead(CALSW) == LOW) cal = true;
  }
  else if(digitalRead(CALSW) == LOW) cal = true;
  else {
    closed = false;
    cal = false;
  }
}

void loop() {
  if(cal) calibrate();
  if(debounce(BUTTON) == LOW && closed && debounceSw(SWITCH) == HIGH) {
    open();
    while(debounce(BUTTON) == LOW);
    closed = false;
  }
  else if(!closed && debounce(BUTTON) == LOW && debounceSw(SWITCH) == HIGH) {
    close();
    while(debounce(BUTTON) == LOW);
    closed = true;
  }
  else if(debounce(BUTTON) == HIGH) stopped();
  if(debounceSw(SWITCH) == HIGH) digitalWrite(13, LOW);
  else if(debounceSw(SWITCH) == LOW) {
    digitalWrite(13, HIGH);
    if(debounce(BUTTON) == LOW) {
      if(!closed) {
        close();
        freakOut();
      }
      else freakOut();
    }
  }
  if(closed) {
    count++;
    delay(10);
  }
  if(!closed) {
    count--;
    delay(10);
  }
  analogWrite(11, count);
  if(count > 64) count = 0;
  if(count < 0) count = 64; 
}

void calibrate() {
  for(int i = 0; i < 255; i++) {
    analogWrite(11, i);
    delay(10);
  }
  while(true) {
    if(debounceSw(SWITCH) == LOW) {
      digitalWrite(11, HIGH);
      while(debounce(BUTTON) == LOW) {
        if(digitalRead(CALSW) == LOW) right.write(180);
        else left.write(180);
      }
      right.write(90);
      left.write(90);
    }
    else if (debounceSw(SWITCH) == HIGH) {
      analogWrite(11, 127);
      while(debounce(BUTTON) == LOW) {
        if(digitalRead(CALSW) == LOW) right.write(0);
        else left.write(0);
      }
      right.write(90);
      left.write(90);
    }
    else analogWrite(11, 64);
  }
}

int debounce(int pin) {

   // read the state of the switch into a local variable:
  int reading = digitalRead(pin);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    buttonState = reading;
  }
  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
  return buttonState;
}

int debounceSw(int pin) {
  int reading = digitalRead(pin);
  if (reading != lastSwitchState) {
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    switchState = reading;
  }
  lastSwitchState = reading;
  return switchState;
}

void stop() {
  right.write(90);
  delay(600);
  left.write(90);
}

void stopped() {
  right.write(90);
  left.write(90);
}

void close() {
  left.write(0);
  right.write(0);
  delay(1295);
  right.write(90);
  delay(350);
  left.write(90);
}

void open() {
  left.write(180);
  right.write(180);
  delay(1300);
  right.write(90);
  delay(500);
  left.write(90);
}

void freakOut() {
  while(debounceSw(SWITCH) == LOW) {
    open();
    left.write(0);
    delay(500);
    right.write(0);
    delay(100);
    left.write(180);
    delay(500);
    right.write(180);
    left.write(0);
    delay(100);
    right.write(0);
    delay(200);
    left.write(180);
    right.write(180);
    delay(100);
    left.write(0);
    right.write(0);
    delay(695);
    right.write(90);
    delay(650);
    left.write(90);
  }
  while(debounce(BUTTON) == LOW);
  open();
  closed = false;
}

void flash() {
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(250);
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(250);
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
}
