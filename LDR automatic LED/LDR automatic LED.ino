/*
    This code regulates the brightness of a LED using
    a potentiometer, converting an ANALOG INPUT
    into a PWM RANGE OUTPUT

    Made by Lucas Mina: https://github.com/Lucasfmina
*/
    
#define POTENTIOMETER = A0;     
#define LED_PIN = 5;
                          
int value = 0;

void setup(){
  pinMode(LED_PIN, OUTPUT); 
}

void loop(){
  value = analogRead(POTENTIOMETER);

  analogWrite(LED_PIN,map (value,0,1023,0,255));
  delay(500);
}