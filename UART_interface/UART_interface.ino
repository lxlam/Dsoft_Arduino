

#define LED 2
#define Button 0 

boolean led_status;
String datacommand;
int led_value = -1;

void IRAM_ATTR led_toggle()
{
    datacommand = "";   
    led_status = digitalRead(LED);
    digitalWrite(LED, !led_status);


    if(led_status == 1)
    {
        led_value = 1; 
    }else
    {
        led_value = 0;
    }
}

void Turn_on_led()
{
    digitalWrite(LED, HIGH);
}

void Turn_off_led()
{
    digitalWrite(LED, LOW);
}

void Blink_led()
{
    while (datacommand == "Blink")
    {
        digitalWrite(LED, !digitalRead(LED));
        Read_serialdata();
        delay(200);
    }
}

void Read_serialdata(){

    if(Serial.available()){
        datacommand = Serial.readString();
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
    Read_serialdata();

    if (datacommand == "ON"){
        Turn_on_led();
        //while(Serial.available()) Serial.read(); // Clear serial buffer
        //datacommand = ""; 
    }else if(datacommand == "OFF"){
        Turn_off_led();
        //while(Serial.available()) Serial.read(); // Clear serial buffer
        //datacommand = "";
    }else if(datacommand == "Blink"){
        Blink_led();
    }


    switch(led_value){
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