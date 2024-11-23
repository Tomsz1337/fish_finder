int URTRIG = 13;         // trigger pin
int sensorPin = A0;     // select the input pin for the potentiometer
int sensorValue = 100;    // variable to store the value coming from the sensor

uint8_t userInput;

void setup()
{
  pinMode(URTRIG, OUTPUT);
  digitalWrite(URTRIG, HIGH);               
  Serial.begin(9600);                       
}
void loop()
{
  if(Serial.available() >0)
  {
    userInput = Serial.read();

    if(userInput == 'g')
    {
      digitalWrite(URTRIG, LOW);
      digitalWrite(URTRIG, HIGH);
      sensorValue = analogRead(sensorPin);
      sensorValue = sensorValue * 1.1;
      Serial.println(sensorValue);
    }
  }
}
