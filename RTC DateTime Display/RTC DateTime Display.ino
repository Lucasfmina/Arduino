/*
    This code turns on a LED when the PIR sensor
    detects heat sources

    Made by Lucas Mina: https://github.com/Lucasfmina
*/
    
#define LED_PIN 4
#define PIR_PIN 8 

void setup(){
  pinMode(LED_PIN,OUTPUT);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
}
 
void loop(){ 

  if (digitalRead(PIR_PIN) == HIGH){
    digitalWrite(LED_PIN, HIGH);
    delay(15000);
    digitalWrite(LED_PIN, LOW);
    }
  delay(500);
}