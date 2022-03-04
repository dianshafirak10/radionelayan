#include <arduino.h>
#include "dra808m.h"
#include  <SoftwareSerial.h>
#include "cw.h"
#include ".\timer.h"
#include <TinyGPS++.h>

#define rxPin 4
#define txPin 3
#define sqPin 12
#define pttPin 9
#define pdPin 10
#define hlPin 7 
#define tonePin 11
#define audioFrequency 550

SoftwareSerial rxtx=SoftwareSerial(rxPin,txPin);
Dra808m dra(sqPin, pttPin, pdPin, hlPin, &rxtx);
 CW morse = CW( tonePin ,14, audioFrequency);
 Timer timer1(60000L);

// Choose two Arduino pins to use for software serial
int RXgPin = 5; //Connect ke TX GPS
int TXgPin = 6; //Connect ke RX GPS

int GPSBaud = 9600;

// Membuat objek TinyGPS++
TinyGPSPlus gps;

// Membuat koneksi serial dengan nama "gpsSerial"
SoftwareSerial gpsSerial(RXgPin, TXgPin);

void setup()
{ boolean ok=false;
  Serial.begin(9600);
  Serial.println("hallo");
  dra.ptt_off();
  dra.wakeup();
  dra.lowpower();
  delay(200);
    dra.send((char*)atCmdHand); 
    delay( 20); //  nach 16.2ms muessten 15 zeichen da sein // after 16.2ms there should be 15 characters
    ok=dra.receive();
    delay(200);

  delay( 20);
  dra.send((char*)atCmdSet); 
  delay( 20); //  nach 16.2ms muessten 15 zeichen da sein
  dra.receive();
  delay( 20);

  //Memulai koneksi serial dengan sensor
  gpsSerial.begin(GPSBaud);
}

void loop()
{ 
  
  
  while (gpsSerial.available()>0)
    if (gps.encode(gpsSerial.read()))
    { 
      dra.ptt_on(); // switches ptt-pin to LOW ; this indicates: It is actulally transmitting, look at Pin 9
      delay( 2000);  // some delay
      
      send_location();
      //send_char2();

      morse.carrier(5000); // sends a continuous tone for 3 seconds
      delay(1000); // some delay
      dra.ptt_off(); // switches ptt-pin to HIGH ; Pin9 is HIGH , this indicates: tx is off
      
      //delay(5000);

      while( !timer1.event() ){} //instead if delay , wait for timer "Timer timer1(60000L);" = 60 seconds
    }
  
    
}
  
  
float mylat;
float mylng;
String str;
String str1 = "h h h ";
String str2 = "vv";
int str_len;
int k;

void send_char()
{
  str = "v v v test de dk2jk dk2jk = pwr 500mw +  ";
  str_len = str.length()+1;
  char contoh[str_len];
  str.toCharArray(contoh,str_len);
  for (k=0; k < strlen(contoh); k=k+1)
  {
    morse.sende_zeichen(contoh[k]);
  }
}

void send_char2()
{
  str = str1+"-6.89335,107.63232"+str2;
  str_len = str.length()+1;
  char contoh[str_len];
  str.toCharArray(contoh,str_len);
  for (k=0; k < strlen(contoh); k=k+1)
  {
    morse.sende_zeichen(contoh[k]);
  }
}

String strlat;
String strlng;
void send_location()
{
  if (gps.location.isValid())
  {
    mylat = gps.location.lat();
    mylng = gps.location.lng();
    strlat = String(mylat,5);
    strlng = String(mylng,5);
    str = "v v v v v"+strlat+","+strlng+str2;
  }
  
  else
  {
    str = str1+"--Location-Not-available--"+str2;
  }
  
  Serial.println(str);
  str_len = str.length()+1;
  char contoh[str_len];
  str.toCharArray(contoh,str_len);
  for (k=0; k < strlen(contoh); k=k+1)
  {
    morse.sende_zeichen(contoh[k]);
  }  
}
