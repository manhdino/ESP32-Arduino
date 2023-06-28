#define TOUCH_PIN 14
#define LED_PIN 23

int touchValue = 0;
const int threshold = 40; //touched: threshold < 40 - > 40 if not touch
void setup() {
    Serial.begin(115200);
    Serial.println("ESP32 Touch Sensor");
    pinMode(LED_PIN,OUTPUT);
}  

void loop() {
    touchValue = touchRead(TOUCH_PIN);
    Serial.println(touchValue);
    if(touchValue < threshold){
      digitalWrite(LED_PIN,HIGH);
      Serial.println("Led On");
      delay(1000);
    }else{
      digitalWrite(LED_PIN,LOW);
      Serial.println("Led Off");
      delay(1000);
    }
    
}
