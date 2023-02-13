/*
    This code sends a payload to another devices using
    an RF transmitter

    Made by Lucas Mina: https://github.com/Lucasfmina
*/
    
#include <VirtualWire.h>
 
byte message[VW_MAX_MESSAGE_LEN];     //Store received messages
byte msgLength = VW_MAX_MESSAGE_LEN;  //Store received messages' lenght

 
void setup()   {
  Serial.begin(115200);
    vw_set_rx_pin(5);            
    vw_setup(2000);             // Bits per sec
    vw_rx_start();             
 
  pinMode(13,OUTPUT);
  Serial.print("Waiting...");  
  delay(2000);
 
}
 
void loop()
{
uint8_t message[VW_MAX_MESSAGE_LEN];    
uint8_t msgLength = VW_MAX_MESSAGE_LEN; 
 
  
    if (vw_get_message(message, &msgLength))   {
        Serial.print("Received: ");        
        digitalWrite(13,HIGH);    
        delay(5000);
        digitalWrite(13,LOW);
        for (int i = 0; i < msgLength; i++) {
          Serial.write(message[i]);
       }
    Serial.println();
    }
}