
#define LED 2
#define Button 0 

uint8_t PressButton = 0;
bool Temp = true;

void setup() {
  Serial.begin(115200);
  pinMode(Button, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  PressButton = digitalRead(Button);
  if (PressButton == LOW)
  {
    while(digitalRead(Button)== LOW);
    Temp = !Temp;
    delay(50); 
  }
  digitalWrite(LED, Temp);
}