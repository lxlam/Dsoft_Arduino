//Hold Button 

#define LED 2
#define Button 0 

int PressButton = 0;

void setup() {
  Serial.begin(115200);
  pinMode(Button, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  PressButton = digitalRead(Button);
  if (PressButton == LOW){
    while(digitalRead(Button)== LOW);
    digitalWrite(LED, HIGH);
    Serial.println("LED ON");
  } else {
    digitalWrite(LED, LOW);
    Serial.println("LED OFF");
  }
}