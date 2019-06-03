typedef struct {
  int pinNum;
  bool pinVal;
} pinInit_t;

void writeNumberOnScreen(pinInit_t* , pinInit_t*);

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int pinDp = 9;
int D1 = 10;
int D2 = 11;
int D3 = 12;
int D4 = 13;

pinInit_t displayOne[] = {
  {D1, LOW},
  {D2, HIGH},
  {D3, HIGH},
  {D4, HIGH}
};

pinInit_t displayTwo[] = {
  {D1, HIGH},
  {D2, LOW},
  {D3, HIGH},
  {D4, HIGH}
};

pinInit_t displayThree[] = {
  {D1, HIGH},
  {D2, HIGH},
  {D3, LOW},
  {D4, HIGH}
};

pinInit_t displayFour[] = {
  {D1, HIGH},
  {D2, HIGH},
  {D3, HIGH},
  {D4, LOW}
};


pinInit_t digitOne[] = {
  {pinA, LOW},
  {pinB, HIGH},
  {pinC, HIGH},
  {pinD, LOW},
  {pinE, LOW},
  {pinF, LOW},
  {pinG, LOW},
  {pinDp, LOW},
};

pinInit_t digitTwo[] = {
  {pinA, HIGH},
  {pinB, HIGH},
  {pinC, LOW},
  {pinD, HIGH},
  {pinE, HIGH},
  {pinF, LOW},
  {pinG, HIGH},
  {pinDp, LOW},
};

pinInit_t digitThree[] = {
  {pinA, HIGH},
  {pinB, HIGH},
  {pinC, HIGH},
  {pinD, HIGH},
  {pinE, LOW},
  {pinF, LOW},
  {pinG, HIGH},
  {pinDp, LOW},
};

pinInit_t digitFour[] = {
  {pinA, LOW},
  {pinB, HIGH},
  {pinC, HIGH},
  {pinD, LOW},
  {pinE, LOW},
  {pinF, HIGH},
  {pinG, HIGH},
  {pinDp, LOW},
};

pinInit_t digitFive[] = {
  {pinA, HIGH},
  {pinB, LOW},
  {pinC, HIGH},
  {pinD, HIGH},
  {pinE, LOW},
  {pinF, HIGH},
  {pinG, HIGH},
  {pinDp, LOW},
};

pinInit_t digitSix[] = {
  {pinA, LOW},
  {pinB, LOW},
  {pinC, HIGH},
  {pinD, HIGH},
  {pinE, HIGH},
  {pinF, HIGH},
  {pinG, HIGH},
  {pinDp, LOW},
};

pinInit_t digitSeven[] = {
  {pinA, HIGH},
  {pinB, HIGH},
  {pinC, HIGH},
  {pinD, LOW},
  {pinE, LOW},
  {pinF, LOW},
  {pinG, LOW},
  {pinDp, LOW},
};

pinInit_t digitEight[] = {
  {pinA, HIGH},
  {pinB, HIGH},
  {pinC, HIGH},
  {pinD, HIGH},
  {pinE, HIGH},
  {pinF, HIGH},
  {pinG, HIGH},
  {pinDp, LOW},
};

pinInit_t digitNine[] = {
  {pinA, HIGH},
  {pinB, HIGH},
  {pinC, HIGH},
  {pinD, LOW},
  {pinE, LOW},
  {pinF, HIGH},
  {pinG, HIGH},
  {pinDp, LOW},
};

pinInit_t digitZero[] = {
  {pinA, HIGH},
  {pinB, HIGH},
  {pinC, HIGH},
  {pinD, HIGH},
  {pinE, HIGH},
  {pinF, HIGH},
  {pinG, LOW},
  {pinDp, LOW},
};

pinInit_t digitBlank[] = {
  {pinA, LOW},
  {pinB, LOW},
  {pinC, LOW},
  {pinD, LOW},
  {pinE, LOW},
  {pinF, LOW},
  {pinG, LOW},
  {pinDp, LOW},
};


void setup() {
  // put your setup code here, to run once:
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDp, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}

void loop() {
  // 1 - 4
  writeNumberOnScreen(displayOne, sizeof(displayOne) / sizeof(pinInit_t), digitOne, sizeof(digitOne) / sizeof(pinInit_t));
  writeNumberOnScreen(displayTwo, sizeof(displayTwo) / sizeof(pinInit_t), digitTwo, sizeof(digitTwo) / sizeof(pinInit_t));
  writeNumberOnScreen(displayThree, sizeof(displayThree) / sizeof(pinInit_t), digitThree, sizeof(digitThree) / sizeof(pinInit_t));
  writeNumberOnScreen(displayFour, sizeof(displayFour) / sizeof(pinInit_t), digitFour, sizeof(digitFour) / sizeof(pinInit_t));
  
  // 5 - 8
  writeNumberOnScreen(displayOne, sizeof(displayOne) / sizeof(pinInit_t), digitFive, sizeof(digitFive) / sizeof(pinInit_t));
  writeNumberOnScreen(displayTwo, sizeof(displayTwo) / sizeof(pinInit_t), digitSix, sizeof(digitSix) / sizeof(pinInit_t));
  writeNumberOnScreen(displayThree, sizeof(displayThree) / sizeof(pinInit_t), digitSeven, sizeof(digitSeven) / sizeof(pinInit_t));
  writeNumberOnScreen(displayFour, sizeof(displayFour) / sizeof(pinInit_t), digitEight, sizeof(digitEight) / sizeof(pinInit_t));
  
  // 9 - 0
  writeNumberOnScreen(displayOne, sizeof(displayOne) / sizeof(pinInit_t), digitNine, sizeof(digitNine) / sizeof(pinInit_t));
  writeNumberOnScreen(displayTwo, sizeof(displayTwo) / sizeof(pinInit_t), digitZero, sizeof(digitZero) / sizeof(pinInit_t));
  writeNumberOnScreen(displayThree, sizeof(displayThree) / sizeof(pinInit_t), digitBlank, sizeof(digitBlank) / sizeof(pinInit_t));
  writeNumberOnScreen(displayFour, sizeof(displayFour) / sizeof(pinInit_t), digitBlank, sizeof(digitBlank) / sizeof(pinInit_t));
}

void writeNumberOnScreen(pinInit_t * selectedDisplay, size_t lengthDisplay, pinInit_t * number, size_t lengthNumber) {
  for (int i = 0; i < lengthDisplay; i++) {
    digitalWrite(selectedDisplay[i].pinNum, selectedDisplay[i].pinVal);
  }
  for (int i = 0; i < lengthNumber; i++) {
    digitalWrite(number[i].pinNum, number[i].pinVal);
  }
  delay(500);
}
