#define thresholdzero 450
#define thresholdone 250
#define thresholdtwo 350
#define thresholdthree 120
#define thresholdfour 250
#define thresholdfive 350
#define thresholdsix 100
#define thresholdseven 350
#define thresholdeight 350
#define thresholdnine 100
#define thresholdten 250
#define thresholdeleven 250
#define thresholdtwelve 350
#define thresholdthirteen 350
#define thresholdfourteen 350
#define thresholdfifteen 350

#define blength 100



int zero = 0;
int one = 0;
int two = 0;
int three = 0;
int four = 0;
int five = 0;
int six = 0;
int seven = 0;
int eight = 0;
int nine = 0;
int ten = 0;
int eleven = 0;
int twelve = 0;
int thirteen = 0;
int fourteen = 0;
int fifteen = 0;

unsigned long intervalzero =80;
unsigned long  prevtimezero=0;

unsigned long intervalone = 60;
unsigned long  prevtimeone=0;

unsigned long intervaltwo = 30;
unsigned long  prevtimetwo=0;

unsigned long intervalthree = 20;
unsigned long  prevtimethree=0;

unsigned long intervalfour = 20;
unsigned long  prevtimefour=0;

unsigned long intervalfive = 30;
unsigned long  prevtimefive= 0;

unsigned long intervalsix = 30;
unsigned long  prevtimesix=0;

unsigned long intervalseven = 30;
unsigned long  prevtimeseven=0;

unsigned long intervaleight = 30;
unsigned long  prevtimeeight=0;

unsigned long intervalnine = 30;
unsigned long  prevtimenine=0;

unsigned long intervalten = 30;
unsigned long  prevtimeten=0;

unsigned long intervaleleven = 30;
unsigned long  prevtimeeleven=0;

unsigned long intervaltwelve = 30;
unsigned long  prevtimetwelve=0;

unsigned long intervalthirteen = 30;
unsigned long  prevtimethirteen=0;

unsigned long intervalfourteen = 30;
unsigned long  prevtimefourteen=0;

unsigned long intervalfifteen = 30;
unsigned long  prevtimefifteen=0;



void setup() {
  Keyboard.begin();
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

boolean noteReady(unsigned long prevtime, unsigned long interval) {
  if((unsigned long)(millis() - prevtime) >= interval) {
    return true;
  }
  else {
    return false;
  }
}


void loop() {
  digitalWrite(3, LOW);
  KeyKnower(0);
  zero = analogRead(A0);

  digitalWrite(3, LOW);
  KeyKnower(1);
  one = analogRead(A0);

  digitalWrite(3, LOW);
  KeyKnower(2);
  two = analogRead(A0);

  digitalWrite(3, LOW);
  KeyKnower(3);
  three = analogRead(A0);

  digitalWrite(3, LOW);
  KeyKnower(4);
  four = analogRead(A0);

  digitalWrite(3, LOW);
  KeyKnower(5);
  five = analogRead(A0);

  digitalWrite(3, LOW);
  KeyKnower(6);
  six = analogRead(A0);

  digitalWrite(3, LOW);
  KeyKnower(7);
  seven = analogRead(A0);

  digitalWrite(6, LOW);
  KeyKnower(8);
  eight = analogRead(A1);

  digitalWrite(6, LOW);
  KeyKnower(9);
  nine = analogRead(A1);

  digitalWrite(6, LOW);
  KeyKnower(10);
  ten = analogRead(A1);

  digitalWrite(6, LOW);
  KeyKnower(11);
  eleven = analogRead(A1);

  digitalWrite(6, LOW);
  KeyKnower(12);
  twelve = analogRead(A1);

  digitalWrite(6, LOW);
  KeyKnower(13);
  thirteen = analogRead(A1);

  digitalWrite(6, LOW);
  KeyKnower(14);
  fourteen = analogRead(A1);

  digitalWrite(6, LOW);
  KeyKnower(15);
  fifteen = analogRead(A1);
  
  
  if(zero >= thresholdzero && noteReady(prevtimezero, intervalzero)) {
    prevtimezero = millis();
    Serial.println(zero);
    Keyboard.print("x");
  }
  if(one >= thresholdone && noteReady(prevtimeone, intervalone)) {
    prevtimeone = millis();
    Serial.println(one);
    Keyboard.print("z");
  }
  if(two >= thresholdtwo && noteReady(prevtimetwo, intervaltwo)) {
    prevtimetwo = millis();
    Serial.println(two);
    Keyboard.print("c");
  }
  if(three >= thresholdthree && noteReady(prevtimethree, intervalthree)) {
    prevtimethree = millis();
    Serial.println(three);
    Keyboard.print("v");
  }
  if(four >= thresholdfour && noteReady(prevtimefour, intervalfour)) {
    prevtimefour = millis();
    Serial.println(four);
    Keyboard.print("b");
  }
  if(five >= thresholdfive && noteReady(prevtimefive, intervalfive)) {
    prevtimefive = millis();
    Serial.println(five);
    Keyboard.print("n");
  }
  if(six >= thresholdsix && noteReady(prevtimesix, intervalsix)) {
    prevtimesix = millis();
    Serial.println(six);
    Keyboard.print("m");
  }
  if(seven >= thresholdseven && noteReady(prevtimeseven, intervalseven)) {
    prevtimeseven = millis();
    Serial.println(seven);
    Keyboard.print(",");
  }
  if(eight >= thresholdeight && noteReady(prevtimeeight, intervaleight)) {
    prevtimeeight = millis();
    Serial.println(eight);
    Keyboard.print(".");
  }
  if(nine >= thresholdnine && noteReady(prevtimenine, intervalnine)) {
    prevtimenine = millis();
    Serial.println(nine);
    Keyboard.print("/");
  }
  if(ten >= thresholdten && noteReady(prevtimeten, intervalten)) {
    prevtimeten = millis();
    Serial.println(ten);
    Keyboard.print("r");
  }
  if(eleven>= thresholdeleven && noteReady(prevtimeeleven, intervaleleven)) {
    prevtimeeleven = millis();
    Serial.println(eleven);
    Keyboard.print("t");
  }
  if(twelve>= thresholdtwelve && noteReady(prevtimetwelve, intervaltwelve)) {
    prevtimetwelve = millis();
    Serial.println(twelve);
    Keyboard.print("y");
  }
  if(thirteen>= thresholdthirteen && noteReady(prevtimethirteen, intervalthirteen)) {
    prevtimethirteen = millis();
    Serial.println(thirteen);
    Keyboard.print("u");
  }
  if(fourteen>= thresholdfourteen&& noteReady(prevtimefourteen, intervalfourteen)) {
    prevtimefourteen = millis();
    Serial.println(fourteen);
    Keyboard.print("i");
  }
  if(fifteen>= thresholdfifteen&& noteReady(prevtimefifteen, intervalfifteen)) {
    prevtimefifteen = millis();
    Serial.println(fifteen);
    Keyboard.print("o");
  }

//LED
  blinker(0, prevtimezero);
  blinker(1, prevtimeone);
  blinker(2, prevtimetwo);
  blinker(3, prevtimethree);
  blinker(4, prevtimefour);
  blinker(5, prevtimefive);
  blinker(6, prevtimesix);
  blinker(7, prevtimeseven);
  blinker(8, prevtimeeight);
  blinker(9, prevtimenine);
  blinker(10, prevtimeten);
  blinker(11, prevtimeeleven);
  blinker(12, prevtimetwelve);
  blinker(13, prevtimethirteen);
  blinker(14, prevtimefourteen);
  blinker(15, prevtimefifteen);
}

void KeyKnower(byte key){
  if (key==0){
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }

  if (key==1){
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }

  if (key==2){
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }

  if (key==3){
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }

  if (key==4){
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }

  if (key==5){
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }

  if (key==6){
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }

  if (key==7){
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }

//for the lwoer set:

  if (key==8){
    digitalWrite(14, LOW);
    digitalWrite(16, LOW);
    digitalWrite(10, LOW);
  }

  if (key==9){
    digitalWrite(14, HIGH);
    digitalWrite(16, LOW);
    digitalWrite(10, LOW);
  }

  if (key==10){
    digitalWrite(14, LOW);
    digitalWrite(16, HIGH);
    digitalWrite(10, LOW);
  }

  if (key==11){
    digitalWrite(14, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(10, LOW);
  }

  if (key==12){
    digitalWrite(14, LOW);
    digitalWrite(16, LOW);
    digitalWrite(10, HIGH);
  }

  if (key==13){
    digitalWrite(14, HIGH);
    digitalWrite(16, LOW);
    digitalWrite(10, HIGH);
  }

  if (key==14){
    digitalWrite(14, LOW);
    digitalWrite(16, HIGH);
    digitalWrite(10, HIGH);
  }

  if (key==15){
    digitalWrite(14, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(10, HIGH);
  }
  
}

void blinker(short num, unsigned long prevtime){

  if(num==0){
    digitalWrite(3,LOW);
    KeyKnower(0);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(3,HIGH);
    }
    else{
      digitalWrite(3,LOW);
    }
  }
  if(num==1){
    digitalWrite(3,LOW);
    KeyKnower(1);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(3,HIGH);
    }
    else{
      digitalWrite(3,LOW);
    }
  }
  if(num==2){
    digitalWrite(3,LOW);
    KeyKnower(2);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(3,HIGH);
    }
    else{
      digitalWrite(3,LOW);
    }
  }
  if(num==3){
    digitalWrite(3,LOW);
    KeyKnower(3);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(3,HIGH);
    }
    else{
      digitalWrite(3,LOW);
    }
  }
  if(num==4){
    digitalWrite(3,LOW);
    KeyKnower(4);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(3,HIGH);
    }
    else{
      digitalWrite(3,LOW);
    }
  }
  if(num==5){
    digitalWrite(3,LOW);
    KeyKnower(5);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(3,HIGH);
    }
    else{
      digitalWrite(3,LOW);
    }
  }
  if(num==6){
    digitalWrite(3,LOW);
    KeyKnower(6);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(3,HIGH);
    }
    else{
      digitalWrite(3,LOW);
    }
  }
  if(num==7){
    digitalWrite(3,LOW);
    KeyKnower(7);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(3,HIGH);
    }
    else{
      digitalWrite(3,LOW);
    }
  }
  if(num==8){
    digitalWrite(6,LOW);
    KeyKnower(8);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(6,HIGH);
    }
    else{
      digitalWrite(6,LOW);
    }
  }
  if(num==9){
    digitalWrite(6,LOW);
    KeyKnower(9);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(6,HIGH);
    }
    else{
      digitalWrite(6,LOW);
    }
  }
  if(num==10){
    digitalWrite(6,LOW);
    KeyKnower(10);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(6,HIGH);
    }
    else{
      digitalWrite(6,LOW);
    }
  }
  if(num==11){
    digitalWrite(6,LOW);
    KeyKnower(11);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(6,HIGH);
    }
    else{
      digitalWrite(6,LOW);
    }
  }
  if(num==12){
    digitalWrite(6,LOW);
    KeyKnower(12);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(6,HIGH);
    }
    else{
      digitalWrite(6,LOW);
    }
  }
  if(num==13){
    digitalWrite(6,LOW);
    KeyKnower(13);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(6,HIGH);
    }
    else{
      digitalWrite(6,LOW);
    }
  }
  if(num==14){
    digitalWrite(6,LOW);
    KeyKnower(14);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(6,HIGH);
    }
    else{
      digitalWrite(6,LOW);
    }
  }
  if(num==15){
    digitalWrite(6,LOW);
    KeyKnower(15);
    if ((unsigned long)(millis()-prevtime) <= blength) {
      digitalWrite(6,HIGH);
    }
    else{
      digitalWrite(6,LOW);
    }
  }
}


/*
void KeyPress1(unsigned long ledterval, unsigned long prevtime, boolean pressor){
  if (unsigned long(millis()-ledterval)>=12){
    digitalWrite(3, HIGH);
  }
  else{
    digitalWrite(3,LOW);
  }
}

*/


