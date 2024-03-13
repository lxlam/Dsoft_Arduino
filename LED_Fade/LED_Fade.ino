#define LED 2

uint8_t freq = 5000;
uint8_t resolution = 8;
uint8_t pwmchannel = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  ledcSetup(pwmchannel, freq, resolution);
  ledcAttachPin(LED, pwmchannel);
}

void loop() {
  for(int dutycycle = 0; dutycycle <= 255; dutycycle++){
    ledcWrite(pwmchannel,dutycycle);
    delay(15);
  }
  for(int dutycycle = 255; dutycycle >= 0; dutycycle--){
    ledcWrite(pwmchannel,dutycycle);
    delay(15);
  }
}