typedef struct {
  int pinNum;
  bool pinVal;
} pinInit_t;

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

//Displays
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

//Digits
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

pinInit_t digitDot[] = {
  {pinA, LOW},
  {pinB, LOW},
  {pinC, LOW},
  {pinD, LOW},
  {pinE, LOW},
  {pinF, LOW},
  {pinG, LOW},
  {pinDp, HIGH},
};

pinInit_t digitGrads[] = {
  {pinA, HIGH},
  {pinB, HIGH},
  {pinC, LOW},
  {pinD, LOW},
  {pinE, LOW},
  {pinF, HIGH},
  {pinG, HIGH},
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

static int LENGTH_NUMBER = 4;

static size_t LENGTH_DISPLAY = sizeof(displayOne) / sizeof(pinInit_t);
static size_t LENGTH_DIGIT = sizeof(digitOne) / sizeof(pinInit_t);  

void setup() {
  Serial.begin(9600); 
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
  char number[] = "2912";
  
  pinInit_t* currentDisplay;
  pinInit_t* digit;

  for(int i = 0; i < sizeof(number); i++){
    currentDisplay = getDisplay(i);
    digit = getDigitDisplay(number[i]);

    writeNumberOnScreen(currentDisplay, digit);
  }
}

void writeNumberOnScreen(pinInit_t * selectedDisplay, pinInit_t * number) {
  for (int i = 0; i < LENGTH_DISPLAY; i++) {
    digitalWrite(selectedDisplay[i].pinNum, selectedDisplay[i].pinVal);
  }
  for (int i = 0; i < LENGTH_DIGIT; i++) {
    digitalWrite(number[i].pinNum, number[i].pinVal);
  }
  delay(5);
}

pinInit_t* getDisplay(int number){
  switch(number){
    case 0:
      return displayOne;
      break;
    case 1:
      return displayTwo;
      break;
    case 2: 
      return displayThree;
      break;
    case 3:
      return displayFour;
      break;  
  }  
}

pinInit_t* getDigitDisplay(char number){
  switch (number){
    case '0':
      return digitZero;
      break;
    case '1':
      return digitOne;
      break;
    case '2':
      return digitTwo;
      break;
    case '3':
      return digitThree;
      break;
    case '4':
      return digitFour;
      break;
    case '5':
      return digitFive;
      break;
    case '6':
      return digitSix;
      break;
    case '7':
      return digitSeven;
      break;
    case '8':
      return digitEight;
      break;
    case '9':
      return digitNine;
      break;
    case '.':
      return digitDot;
      break;
    default:
      return digitBlank;
      break;  
  }
}
