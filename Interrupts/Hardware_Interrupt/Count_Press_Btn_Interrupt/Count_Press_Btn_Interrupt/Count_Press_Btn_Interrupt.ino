#define BUTTON_PIN 33
int numPress = 0;
bool isPress = false;

void IRAM_ATTR btnPush(){
   numPress += 1;
   isPress = true;
}
void setup() {
  Serial.begin(115200);
   //INPUT_PULLUP --> ban đầu mặc định ở HIGH, Nhấn nút LOW, thả nút HIGH (HI_TO_LOW)
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  attachInterrupt(BUTTON_PIN, btnPush, FALLING);
}


void loop() {
    if(isPress){
        Serial.printf("Button has been pressed %u times\n",numPress);
        isPress = false;
    }
}