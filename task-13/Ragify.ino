int maxdist = 0;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  maxdist = 100;
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  Serial.print(cm);
  Serial.println("cm");
  if (cm <= maxdist) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  delay(1000);
}