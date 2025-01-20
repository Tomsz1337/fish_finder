#define echoPin 2 
#define trigPin 12 

long duration; 
int distance; 
volatile unsigned long LastPulseTime;
char userInput ;

void echoPinISR()
{
  static unsigned long startTime;

  if(digitalRead(2))
  {
    startTime = micros();
  } 
  else
  {
    LastPulseTime = micros() - startTime;
  } 
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  attachInterrupt(0, echoPinISR, CHANGE); 
  Serial.begin(9600); 
}

void loop() {

  if(Serial.available() > 0)
  {
    userInput = Serial.read();

    if(userInput == 'g')
    { 
      delayMicroseconds(5);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10); 
      digitalWrite(trigPin, LOW);
      Serial.println((LastPulseTime/58.2),1);
       
    }
  }  
}

