#define BUTTON_PIN 23
#define LED_PIN 19
bool isPress = false;

void IRAM_ATTR btnPress(){
  // không được cho Serial.println ở  trong hàm Interrupt
  // vì hàm Interrupt chạy rất nhanh và hàm Serial chạy rất lâu nên sẽ sinh ra lỗi ESP32 Core 1 panic'ed(Interrupt wdt timeout on CPU1)
   isPress = true;
}
void setup() {
  Serial.begin(115200);
   //INPUT_PULLUP --> ban đầu mặc định ở HIGH, Nhấn nút LOW, thả nút HIGH (HI_TO_LOW)
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  pinMode(LED_PIN,OUTPUT);
  attachInterrupt(BUTTON_PIN, btnPress, FALLING);
  digitalWrite(LED_PIN,LOW);
}


void loop() {
  if(isPress){
      digitalWrite(LED_PIN,HIGH);
      delay(1000);
      Serial.println("LED On");
      isPress = false;
      digitalWrite(LED_PIN,LOW);
      Serial.println("LED Off");
  }
}


