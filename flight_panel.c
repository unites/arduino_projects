/*
   Teensy becomes a USB joystick with 16 or 32 buttons and 6 axis input

   You must select Joystick from the "Tools > USB Type" menu

   Pushbuttons should be connected between the digital pins and ground.
   Potentiometers should be connected to analog inputs 0 to 5.

   This example code is in the public domain.
*/

// Configure the number of buttons.  Be careful not
// to use a pin for both a digital button and analog
// axis.  The pullup resistor will interfere with
// the analog voltage.
#include <ResponsiveAnalogRead.h>
#include <Bounce.h>

ResponsiveAnalogRead a0(A0, true);
ResponsiveAnalogRead a1(A1, true);
ResponsiveAnalogRead a2(A2, true);
ResponsiveAnalogRead a3(A3, true);
ResponsiveAnalogRead a4(A4, true);

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
// 10 = 10 ms debounce time
// which is appropriate for
// most mechanical pushbuttons
Bounce b0 = Bounce(0, 10);
Bounce b1 = Bounce(1, 10);  
Bounce b2 = Bounce(2, 10);  
Bounce b3 = Bounce(3, 10); 
Bounce b4 = Bounce(4, 10);
Bounce b5 = Bounce(5, 10);
Bounce b6 = Bounce(6, 10);
Bounce b7 = Bounce(7, 10);
Bounce b8 = Bounce(24, 10);
Bounce b9 = Bounce(25, 10);  
Bounce b10 = Bounce(10, 10);  
Bounce b11 = Bounce(11, 10); 
Bounce b12 = Bounce(12, 10);
Bounce b13 = Bounce(8, 10);
Bounce b14 = Bounce(9, 10);
Bounce b15 = Bounce(37, 10);  
Bounce b16 = Bounce(36, 10);  
Bounce b17 = Bounce(35, 10); 
Bounce b18 = Bounce(34, 10);
Bounce b19 = Bounce(40, 10);
Bounce b20 = Bounce(41, 10);

const int greenPin =  23;
const int redPin =  22;

void setup() {
//  Serial.begin(9600);
  Joystick.useManualSend(true);
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  pinMode(36, INPUT_PULLUP);
  pinMode(37, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(40, INPUT_PULLUP);
  pinMode(41, INPUT_PULLUP);
  
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  a0.update();
  a1.update();
  a2.update();
  a3.update();
  a4.update();

  b0.update();
  b1.update();
  b2.update();
  b3.update();
  b4.update();
  b5.update();
  b6.update();
  b7.update();
  b8.update();
  b9.update();
  b10.update();
  b11.update();
  b12.update();
  b13.update();
  b14.update();
  b15.update();
  b16.update();
  b17.update();
  b18.update();
  b19.update();
  b20.update();
  
  Joystick.X(a0.getValue());
  Joystick.Y(a1.getValue());
  Joystick.Z(a2.getValue());
  Joystick.sliderLeft(a3.getValue());
  Joystick.sliderRight(a4.getValue());
 // Check each button for "falling" edge.
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (b0.fallingEdge()) {
    Joystick.button(1, 1);
  }
  if (b1.fallingEdge()) {
    Joystick.button(2, 1);
  }
  if (b2.fallingEdge()) {
    Joystick.button(3, 1);
  }
  if (b3.fallingEdge()) {
    Joystick.button(4, 1);
  }
  if (b4.fallingEdge()) {
    Joystick.button(5, 1);
  }
  if (b5.fallingEdge()) {
    Joystick.button(6, 1);
  }
  if (b6.fallingEdge()) {
    Joystick.button(7, 1);
  }
  if (b7.fallingEdge()) {
    Joystick.button(8, 1);
  }
  if (b8.fallingEdge()) {
    Joystick.button(9, 1);
    digitalWrite(redPin, HIGH);
  }
  if (b9.fallingEdge()) {
    Joystick.button(10, 1);
    digitalWrite(greenPin, HIGH);
  }
  if (b10.fallingEdge()) {
    Joystick.button(11, 1);
  }
  if (b11.fallingEdge()) {
    Joystick.button(12, 1);
  }
  if (b12.fallingEdge()) {
    Joystick.button(13, 1);
  }
  if (b13.fallingEdge()) {
    Joystick.button(14, 1);
  }
  if (b14.fallingEdge()) {
    Joystick.button(15, 1);
  }
  if (b15.fallingEdge()) {
    Joystick.button(16, 1);
  }
  if (b16.fallingEdge()) {
    Joystick.button(17, 1);
  }
  if (b17.fallingEdge()) {
    Joystick.button(18, 1);
  }
  if (b18.fallingEdge()) {
    Joystick.button(19, 1);
  }
  if (b19.fallingEdge()) {
    Joystick.button(20, 1);
  }
  if (b20.fallingEdge()) {
    Joystick.button(21, 1);
  }

  // Check each button for "rising" edge
  // Update the Joystick buttons only upon changes.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (b0.risingEdge()) {
    Joystick.button(1, 0);
  }
  if (b1.risingEdge()) {
    Joystick.button(2, 0);
  }
  if (b2.risingEdge()) {
    Joystick.button(3, 0);
  }
  if (b3.risingEdge()) {
    Joystick.button(4, 0);
  }
  if (b4.risingEdge()) {
    Joystick.button(5, 0);
  }
  if (b5.risingEdge()) {
    Joystick.button(6, 0);
  }
  if (b6.risingEdge()) {
    Joystick.button(7, 0);
  }
  if (b7.risingEdge()) {
    Joystick.button(8, 0);
  }
  if (b8.risingEdge()) {
    Joystick.button(9, 0);
    digitalWrite(redPin, LOW);
  }
  if (b9.risingEdge()) {
    Joystick.button(10, 0);
    digitalWrite(greenPin, LOW);
  }
  if (b10.risingEdge()) {
    Joystick.button(11, 0);
  }
  if (b11.risingEdge()) {
    Joystick.button(12, 0);
  }
  if (b12.risingEdge()) {
    Joystick.button(13, 0);
  }
  if (b13.risingEdge()) {
    Joystick.button(14, 0);
  }
  if (b14.risingEdge()) {
    Joystick.button(15, 0);
  }
  if (b14.risingEdge()) {
    Joystick.button(15, 0);
  }
  if (b15.risingEdge()) {
    Joystick.button(16, 0);
  }
  if (b16.risingEdge()) {
    Joystick.button(17, 0);
  }
  if (b17.risingEdge()) {
    Joystick.button(18, 0);
  }
  if (b18.risingEdge()) {
    Joystick.button(19, 0);
  }
  if (b19.risingEdge()) {
    Joystick.button(20, 0);
  }
  if (b20.risingEdge()) {
    Joystick.button(21, 0);
  }

  Joystick.send_now();

  delay(10);
}
