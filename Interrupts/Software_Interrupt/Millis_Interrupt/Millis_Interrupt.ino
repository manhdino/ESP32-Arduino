
#define LED_PIN 19
// Hẹn giờ tự động bật tắt LED trong 5s

// biến trạng thái Led
int ledState = 0;
 
// Giá trị lần cuối cùng được cập nhật
unsigned long previousMillis = 0;   
 
const long interval = 5000; // giá trị delay (milliseconds) - 5s 
 
void setup() {
  // set led là ouput
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop(){
  // khởi tạo một biến lưu giá trị hiện tại của Timer
   unsigned long currentMillis = millis();
   Serial.print("Interval: ");
   Serial.println(currentMillis - previousMillis);
   if((currentMillis - previousMillis) > interval){//nếu delay > 5s
      previousMillis = currentMillis;
      ledState = 1 - ledState;
      digitalWrite(LED_PIN,ledState);
   }
}