int TRIG = 18;
int ECO = 19;
int distanciaOriginal=0;
const int PIN_ROJO=22;
const int PIN_VERDE=23;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(PIN_ROJO,OUTPUT);
  pinMode(PIN_VERDE,OUTPUT);
}

void loop()
{
  delay(100);
  distanciaOriginal = 0.01723 * readUltrasonicDistance(TRIG, ECO);
  Serial.print(distanciaOriginal);
  Serial.println("cm");
  if(distanciaOriginal%5==0){
    digitalWrite(PIN_ROJO, HIGH);
    digitalWrite(PIN_VERDE, LOW);
  }
  else{
    digitalWrite(PIN_ROJO, LOW);
    digitalWrite(PIN_VERDE, HIGH);
  }
}

