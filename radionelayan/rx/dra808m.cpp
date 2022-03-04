
#include "dra808m.h"
#include  <SoftwareSerial.h>



Dra808m::Dra808m(char sqPin, char pttPin, char pdPin, char hlPin, SoftwareSerial *rxtx)
{
  _sq  = sqPin;   // low amplifier on
  _ptt = pttPin;  // low tx, high rx
  _pd  = pdPin;   // low power down = sleepmode
  _low = hlPin;   // low = power low 0.5W

  digitalWrite( _ptt,HIGH); // untuk Tx, PTT disambung ke ground Arduino
  digitalWrite( _pd,LOW);   //pin PD disambung ke 3.3V Arduino
  digitalWrite( _low,LOW);

  pinMode( _sq , INPUT );
  pinMode( _ptt, OUTPUT);
  pinMode( _pd , OUTPUT);
  pinMode( _low, OUTPUT);
  this->rxtx=rxtx;
  rxtx->begin(9600);
}
void Dra808m::ptt_on()  { 
  digitalWrite( _ptt,LOW); 
}
void Dra808m::ptt_off() { 
  digitalWrite( _ptt,HIGH);  
}
boolean Dra808m::squelch()   {  
  return !digitalRead(_sq); 
}
void Dra808m::sleep()            { 
  digitalWrite( _pd,LOW);   
}
void Dra808m::wakeup()           { 
  digitalWrite( _pd,HIGH);  
}
void Dra808m::lowpower()         { 
  digitalWrite( _low,LOW);  
}
void Dra808m::highpower()        { 
  digitalWrite( _low,HIGH); 
}

void Dra808m::send(char *cmd)
{

  //commandFormat: AT+DMOCONNECT <CR><LF>
  //Module response: +DMOCONNECT: 0 <CR><LF>
  int i;
  for(i=0;i< strlen(cmd);i++)
  {
    rxtx->write(cmd[i]);
  }
  rxtx->write(CR);
  rxtx->write(LF);
  testIndex  = (strlen(cmd) < 17) ? 12:13;

}
boolean Dra808m::receive()
{
  boolean success=false;
  //commandFormat: AT+DMOCONNECT <CR><LF>
  //Module response: +DMOCONNECT: 0 <CR><LF>
  int i;
  int n;

  rxtx->listen();
  n=rxtx->available();
  if(n>0 ){
    for(i=0;i<n; i++)
    {
      rxBuffer[i]=rxtx->read();
    }
    rxBuffer[i]=0;
    Serial.print(testIndex);
    Serial.println(rxBuffer);
    if ( rxBuffer[testIndex]== '0' )
    {
      Serial.println("ack ok");
      success =true;
    }
    else
    {
      Serial.println("*** no ack **");
    }
  }
  return success;
}
