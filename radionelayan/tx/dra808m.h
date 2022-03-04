#include  <SoftwareSerial.h>
#include <arduino.h>

#ifndef _dra808m_h_
#define _dra808m_h_

class SoftwareSerial;
const char atCmdHand[]={
  "AT+DMOCONNECT"};
const char atCmdSet[]={
  //"AT+DMOSETGROUP=0,434.6500,438.8750,00,4"};
  "AT+DMOSETGROUP=0,156.5000,156.5000,00,4"};
//"AT+DMOSETGROUP=GBW,TFV,RFV,CXCSS,SQ"};
#define CR 0x0d
#define LF 0x0a
#define Handshake 0
#define Setting   1

class Dra808m{
public:
  void send(char *cmd);
  boolean receive();
  Dra808m(char sqPin, char pttPin, char pdPin, char hlPin, SoftwareSerial *rxtx);
  void ptt_on();
  void ptt_off();
  boolean squelch();
  void sleep();
  void wakeup();
  void lowpower();
  void highpower();
private:
  char _sq;
  char _ptt; 
  char _pd; 
  char _low;
  char _rxd;
  char _txd;
  SoftwareSerial *rxtx;
  char rxBuffer[20];
  int testIndex;

};
#endif // _dra808m_h_
