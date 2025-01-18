#define echoPin 2 
#define trigPin 12 

long duration; 
int distance; 
volatile unsigned long LastPulseTime;
char userInput ;

void EchoPinISR() {
  static unsigned long startTime;

  if (digitalRead(2)) // Gone HIGH
    startTime = micros();
  else  // Gone LOW
  LastPulseTime = micros() - startTime;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  attachInterrupt(0, EchoPinISR, CHANGE);  // Pin 2 interrupt on any change
  Serial.begin(115200); 
}
void loop() {

  if(Serial.available() > 0)
  {
    userInput = Serial.read();

    if(userInput == 'g')
    {
      digitalWrite(trigPin, LOW); 
      delayMicroseconds(5); 
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10); 
      digitalWrite(trigPin, LOW);
      Serial.println((LastPulseTime/58.2),1);
    }
  //delay(100);
  }  
}

