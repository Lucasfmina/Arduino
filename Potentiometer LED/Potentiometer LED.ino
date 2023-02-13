/*
    This code displays the time and the temperature using
    an RTC sensor (without battery) and a TM1637 display

    Made by Lucas Mina: https://github.com/Lucasfmina
*/
    
#include <RtcDS3231.h>
#include <Wire.h> 
#include <TM1637Display.h>

RtcDS3231<TwoWire> Rtc(Wire);
RtcDateTime   date_time;

#define CLK 3
#define DIO 4

TM1637Display tm(CLK, DIO);

void setup(){
  tm.setBrightness(3);
  tm.clear(); 
  Rtc.Begin();
  Rtc.SetDateTime(RtcDateTime(2022,12,14,14,34,00));  //setting the date and time

  if (!Rtc.GetIsRunning()){
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
  }
}

void loop(){
  
  RtcTemperature temp = Rtc.GetTemperature();
  date_time = Rtc.GetDateTime();     
  tm.showNumberDec(temp.AsFloatDegC(),true,4,0);  
  delay(3000);
  tm.clear();    
  tm.showNumberDecEx(date_time.Hour()*100 + date_time.Minute(),0b11100000,false,4,0); 
  delay(27000);
}