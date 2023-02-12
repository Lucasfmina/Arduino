/*
  This code displays the distance between the HC-SR04 Ultrasonic
  Sensor and the nearest surface in its front on a TM1637 display. 
  The distance is calculated while the button is being pressed and
  remains on the display until the next measurement. During 
  the calculation of the distance, an LED will be turned on.

  Made by Lucas Mina https://github.com/Lucasfmina
*/

#include <TM1637Display.h>

//Pin mapping
#define LED_PIN 13
#define SENSOR_ECHO 6     
#define SENSOR_TRIGGER 5   
#define DISPLAY_CLK 4    
#define DISPLAY_DIO 3   
#define BUTTON_PIN 2  

long cm, duration;
boolean current_status = LOW;
boolean last_status=LOW;

//Creates an instance of the display
TM1637Display tm(DISPLAY_CLK, DISPLAY_DIO);

//Debounce method
boolean debounce(boolean last_status){
  boolean current = digitalRead(BUTTON_PIN); 
  if( last_status != current){
  delay(5); 
  current = digitalRead(BUTTON_PIN); 
  } 
  return current;
}


void setup() {

  //Set the outputs
  pinMode(SENSOR_TRIGGER, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  //Set the brightness and clears the display before displaying new data.
  tm.setBrightness(3);
  tm.clear(); 
}
 
void loop() {

  //Initializes the distance with a invalid value in order
  //to do a validation process based on the especifications
  //of the HC-SR04 datasheet
  cm = -1; 

  current_status = debounce(last_status);
  if(current_status){
    last_status = current_status;
    //Turns on a LED, indicating that the measurements are being taken
    digitalWrite(LED_PIN, HIGH);
    //Calculates and recalculates the distance until it reaches a valid value
    while(cm < 2 || cm > 400){ 
      digitalWrite(SENSOR_TRIGGER, LOW);
      delayMicroseconds(5);
      digitalWrite(SENSOR_TRIGGER, HIGH);
      delayMicroseconds(10);
      digitalWrite(SENSOR_TRIGGER, LOW);

      //Calculates the distance (in centimeters) to the object 
      //based on readings from the sensor"
      pinMode(SENSOR_ECHO, INPUT);
      duration = pulseIn(SENSOR_ECHO, HIGH);
      cm = (duration/2) / 29.1;
    }
    //Displays the distance and waits, so debouncing isn't necessary
    tm.showNumberDec(cm, false, 4, 0);
    delay(150);
  }else{
    digitalWrite(LED_PIN, LOW);
  }
}