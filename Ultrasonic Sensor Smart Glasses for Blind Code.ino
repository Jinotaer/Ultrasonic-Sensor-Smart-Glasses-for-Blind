const int trigPin = 3;
const int echoPin = 2;
const int buzzer = 4;

long duration;
int distance;
const float speedOfSound = 0.0343; // Adjust for your environment

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  if (duration > 0 && duration < 40000) { // Validate pulse duration
    distance = (duration * speedOfSound) / 2;
  } else {
    distance = 999; // "No object" condition
  }

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 45) {
    digitalWrite(buzzer, HIGH);
    delay(100); // Debounce
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(100); // Add loop delay for stability
}
