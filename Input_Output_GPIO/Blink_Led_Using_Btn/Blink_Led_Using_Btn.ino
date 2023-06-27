#define BUTTON_PIN 19
#define LED_PIN 23
int  btnState = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  pinMode(LED_PIN,OUTPUT);
  
}
//INPUT_PULLUP --> ban đầu ở HIGH, Nhấn nút LOW, thả nút HIGH (HI_TO_LOW)
void loop() {
   // On Of Led
  //  digitalWrite(LED_PIN, HIGH);      // sets the digital pin 0 on
	// delay(1000);                // waits for a second
	// digitalWrite(LED_PIN, LOW);       // sets the digital pin 0 off
	// delay(1000);  

   // On Off Led using Btn
   btnState = digitalRead(BUTTON_PIN);
   Serial.println(btnState);
   if(btnState == LOW){ //nhan nut led sang 1s xong roi tat
         digitalWrite(LED_PIN, HIGH);
         delay(1000);
         digitalWrite(LED_PIN,LOW);
   }
   else{
     digitalWrite(LED_PIN,LOW);
   }
}
