//Добавяне на библиотеката keyboard.h, чрез която въвеждаме 
#include <Keyboard.h>

#define btn1_pin 2
#define btn2_pin 3
#define btn3_pin 4
#define btn4_pin 5
#define btn5_pin 6
#define btn6_pin 7
#define btn7_pin 8
#define btnR_pin 9

int btn1;
int btn2;
int btn3;
int btn4;
int btn5;
int btn6;
int btn7;
int btnR;

void setup() {
  delay(2500);
  pinMode(btn1_pin, INPUT_PULLUP);
  pinMode(btn2_pin, INPUT_PULLUP);
  pinMode(btn3_pin, INPUT_PULLUP);
  pinMode(btn4_pin, INPUT_PULLUP);
  pinMode(btn5_pin, INPUT_PULLUP);
  pinMode(btn6_pin, INPUT_PULLUP);
  pinMode(btn7_pin, INPUT_PULLUP);
  pinMode(btnR_pin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  static struct {
    String current;
    int count;
  } state = {"neutral", 0};
  
  if (digitalRead(btn1_pin) == LOW) {
    state.current = "gear1";
  }
  else if (digitalRead(btn2_pin) == LOW) {
    state.current = "gear2";
  }
  else if (digitalRead(btn3_pin) == LOW) {
    state.current = "gear3";
  }
  else if (digitalRead(btn4_pin) == LOW) {
    state.current = "gear4";
  }
  else if (digitalRead(btn5_pin) == LOW) {
    state.current = "gear5";
  }
  else if (digitalRead(btn6_pin) == LOW) {
    state.current = "gear6";
  }
  else if (digitalRead(btn7_pin) == LOW) {
    state.current = "gear7";
  }
  else if (digitalRead(btnR_pin) == LOW) {
    state.current = "gearR";
  }
  else {
    if (state.current == "neutral") {
      state.count++;
    }
    else {
      state.current = "neutral";
      state.count = 1;
    }
  }
  
  if (state.current == "neutral" && state.count >= 2) {
    Keyboard.releaseAll();
  }
  else {
    if (state.current == "gear1") {
      delay(10);
      Keyboard.press('1');
    }
    if (state.current == "gear2") {
      delay(10);
      Keyboard.press('2');
    }
    if (state.current == "gear3") {
      delay(10);
      Keyboard.press('3');
    }
    if (state.current == "gear4") {
      delay(10);
      Keyboard.press('4');
    }
    if (state.current == "gear5") {
      delay(10);
      Keyboard.press('5');
    }
    if (state.current == "gear6") {
      delay(10);
      Keyboard.press('6');
    }
    if (state.current == "gear7") {
      delay(10);
      Keyboard.press('7');
    }
    if (state.current == "gearR") {
      delay(10);
      Keyboard.press('8');
    }
  }
  delay(10);
}
