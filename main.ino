const int ldrPin = 8;      
const int relayPin = 7; 
unsigned long previousMillis = 0;  
// const long interval = 900000;
const long interval = 20000;
// change the interval based on after how long you wanna get tazed
const bool alreadyActivated = false;

void setup() {
  pinMode(ldrPin, INPUT);  
  pinMode(relayPin, OUTPUT); 
  digitalWrite(relayPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(relayPin, LOW);
  bool ldrState = digitalRead(ldrPin);
  unsigned long currentMillis = millis();
  Serial.println(ldrState);
  if (ldrState == LOW) {


    previousMillis = currentMillis;
  } else {

    if ((currentMillis - previousMillis >= interval ) & !alreadyActivated) {
      digitalWrite(relayPin, LOW);
      Serial.println("activated wohoo");
      delay(1000);
      digitalWrite(relayPin,HIGH);
      

  }
}
}
