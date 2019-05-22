const int analogPin = A0;
const int ledCount = 10;
int ledPins[]={
  2,3,4,5,6,7,8,9,10,11
};
void setup() {
  // put your setup code here, to run once:
  for(int thisLed = 0; thisLed < ledCount; thisLed++){
    pinMode(ledPins[thisLed], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorReading= analogRead(analogPin);
  int ledLevel = map(sensorReading,60,220,ledCount,0);
  for(int thisLed = 0;thisLed < ledCount ;thisLed++){
    if(thisLed<ledLevel){
      digitalWrite(ledPins[thisLed],HIGH);
    }
    else{
      digitalWrite(ledPins[thisLed],LOW);
    }
  }
  Serial.println(sensorReading);
  delay(2);
}
