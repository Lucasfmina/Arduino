/*
    This code sends a payload to another devices using
    an RF transmitter

    Made by Lucas Mina: https://github.com/Lucasfmina
*/
    
#include <VirtualWire.h>

String message;

void setup(){
  vw_set_tx_pin(8);
  vw_setup(2000);  
}
 
void loop(){
  String payload="X";
  char data[2];    
  payload.toCharArray(data,2);  
  send(data);
  delay(30000);
} 
 
void send (char *message){
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); 