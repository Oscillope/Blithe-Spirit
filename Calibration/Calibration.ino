//Door calibration
#include <Servo.h>

#define BUTTON 2
#define SPEED 255
#define L 1
#define R 2
Servo left;
Servo right;
int start;
boolean closed;
int door = 1;
int count;
int buttonState = HIGH;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers


void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  left.attach(9);
  right.attach(10);
  left.write(90);
  right.write(90);
  closed = true;
  Serial.begin(9600);
  Serial.println("Hello, world!");
  Serial.println("Door calibration routine");
}

void loop() {
  switch(door) {
     case 0:
       count = 0;
       left.write(90);
       Serial.println("Currently calibrating Door L, open state.");
       Serial.println("When ready, hold button until lever is touching door.");
       while(debounce(BUTTON) == HIGH) delay(1);
       start = millis();
       while(debounce(BUTTON) == LOW) {
         left.write(180);
       }
       left.write(90);
       count = (millis() - start);
       Serial.print("Delay: ");
       Serial.println(count);
       door++;
       break;
     case 1:
       count = 0;
       left.write(90);
       Serial.println("Currently calibrating Door L, closed state.");
       Serial.println("When ready, hold button until lever is touching door.");
       while(debounce(BUTTON) == HIGH) delay(1);
       start = millis();
       while(debounce(BUTTON) == LOW) {
         left.write(0);
       }
       left.write(90);
       count = (millis() - start);
       delay(1000);
       Serial.print("Delay: ");
       Serial.println(count);
       door++;
       break;
     case 2:
       count = 0;
       right.write(90);
       Serial.println("Currently calibrating Door R, open state.");
       Serial.println("When ready, hold button until lever is touching door.");
       while(debounce(BUTTON) == HIGH) delay(1);
       start = millis();
       while(debounce(BUTTON) == LOW) {
         right.write(180);
       }
       right.write(90);
       count = (millis() - start);
       Serial.print("Delay: ");
       Serial.println(count);
       door++;
       break;
     case 3:
       count = 0;
       right.write(90);
       Serial.println("Currently calibrating Door R, closed state.");
       Serial.println("When ready, hold button until lever is touching door.");
       while(debounce(BUTTON) == HIGH) delay(1);
       start = millis();
       while(debounce(BUTTON) == LOW) {
         right.write(0);
       }
       right.write(90);
       count = (millis() - start);
       Serial.print("Delay: ");
       Serial.println(count);
       door++;
       break;
     default:
       left.write(90);
       right.write(90);
       break;
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
