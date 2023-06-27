#define DAC1 25

void setup() {
    Serial.begin(115200);
}
void loop() {
//thay đổi giá trị này và quan sát
// Value = 255 là sáng nhất
// Độ sáng giảm dần từ 255 về 0 
   int Value =  200; 
  // dacWrite(DAC1, Value);
   for(int i = Value;i > 150;i--){
     dacWrite(DAC1,i);
     delay(100);
   }
   delay(1000);
}
