// =========================
// B31DG - EMBEDDED SOFTWARE
// =========================
//       ASSIGNMENT 1 
// 
// Lucas Isaac
//
// =========================

// definition of the pins

#define signal_A_pin 15
#define signal_B_pin 21
#define button_1 22
#define button_2 23

// definition of the parameters 

const int a = 9*100; // width of 1st pulse
const int b = 8*100; // width of space between pulses
const int c = 1+4; // number of pulses in a block
const int d = 1*500; // space between pulse blocks

int b_time = b; // variable to change the time of b (mode 4) 
int d_time = d; // variable to change the time of d (mode 4)


void setup() {
  // signal A and B are outputs
  pinMode(signal_A_pin, OUTPUT);
  pinMode(signal_B_pin, OUTPUT);
  // push buttons are defined on inputs
  pinMode(button_1,INPUT);
  pinMode(button_2,INPUT);
}


void loop() {
  if (digitalRead(button_2) == HIGH){ // case of button 2 is pushed, activate the mode
    // mode 4 : the time b and d are divided by 2
    b_time = b/2;
    d_time = d/2;
  }
  else{ // if not, keep the normal mode with normal times
    b_time = b;
    d_time = d;
  }
  if(digitalRead(button_1) == LOW){ // while the button 1 is not push, do the following part
    digitalWrite(signal_B_pin, HIGH); //we first use the sig B for 50 microseconds
    delayMicroseconds(50); //wait 50 microseconds
    digitalWrite(signal_B_pin, LOW); //the signal B is low for the rest of the stream of pulses
    for(int i=0; i<c; i++){ // repeat the following part c times
      digitalWrite(signal_A_pin, HIGH); // switch on the LED A
      delayMicroseconds(a + i*50); // the delay of a increase of 50 microseconds each time we wait
      digitalWrite(signal_A_pin, LOW); // switch off the LED A
      delayMicroseconds(b_time); // wait b microseconds with the signal A low
      }
    digitalWrite(signal_A_pin, LOW); // turn off the LED A
    delayMicroseconds(d_time); // wait d microseconds before use a new stream of pulses
  }
  else{ // if the button 1 is pushed, stop the pulses of stream
    digitalWrite(signal_A_pin, LOW); // swith off the LED A
    digitalWrite(signal_B_pin, LOW); // switch off the LED B
  }
}
