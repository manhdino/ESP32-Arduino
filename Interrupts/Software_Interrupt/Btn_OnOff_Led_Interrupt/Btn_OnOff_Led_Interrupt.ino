
#define LED_PIN 19
#define BTN_PIN 23
// Bấm nút tự động bật LED trong 5s sau đó tự động tắt 

bool startTimer = false;
 
// Giá trị lần cuối cùng được cập nhật
unsigned long previousMillis = 0;   
 
unsigned long interval = 5000; // giá trị delay (milliseconds) - 5s 

void IRAM_ATTR BtnPress() {
      digitalWrite(LED_PIN, HIGH);
      startTimer = true;
      previousMillis = millis();
}

void setup() {
  // set led là ouput
  Serial.begin(115200);
  pinMode(BTN_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN_PIN), BtnPress, FALLING);
  pinMode(LED_PIN, OUTPUT);
}

void loop(){
  // khởi tạo một biến lưu giá trị hiện tại của Timer
   unsigned long currentMillis = millis();
   if(startTimer && (currentMillis - previousMillis > interval)){//nếu delay > 5s
      Serial.println(currentMillis - previousMillis);// 5001
      digitalWrite(LED_PIN,LOW);
      startTimer = false;
   }
}