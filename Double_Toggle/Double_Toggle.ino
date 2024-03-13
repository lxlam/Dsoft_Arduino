#define LED 2
#define Button 0 

uint8_t PressButton = 0;
bool Temp = true;
uint8_t Counters = 0;

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
    Counters++;
    delay(50); 
  }
  if (Counters == 2)
  {
    Temp = !Temp;
    Counters = 0;
  }
  digitalWrite(LED, Temp);
}