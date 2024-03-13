

#define LED 2

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  Serial.println("LED ON");
  delay(500);
  digitalWrite(LED, LOW);
  Serial.println("LED OFF");
  delay(500);
}