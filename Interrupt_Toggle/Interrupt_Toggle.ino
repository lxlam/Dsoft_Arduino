#define LED 2
#define Button 0 

int led_value = -1;

void IRAM_ATTR led_toggle()
{
    digitalWrite(LED, !digitalRead(LED));
    if(digitalRead(LED)==1)
    {
        led_value = 1; 
    }else{
        led_value = 0;
    }
    
}

void setup() {
    Serial.begin(115200);
    pinMode(Button, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
    attachInterrupt(Button,led_toggle, RISING);
}


void loop() 
{
    switch(led_value)
    {
        case 1:
            Serial.println("LED ON");
            led_value = -1;
            break;
        case 0:
            Serial.println("LED OFF");
            led_value = -1;
            break;
    }
}