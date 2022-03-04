
#include <arduino.h>
#include "timer.h"

// Kelas Timer dengan fungsi Timer yang berisi variabel x dalam bentuk variabel long
Timer:: Timer(long x)   // long variables are extended size variables for number storage
{
  interval( x);         // fungsi Timer memiliki variabel interval bernama x
}

// Kelas Timer dengan fungsi interval berisi variabel
void Timer::interval(long x)
{
  _interval = x;
  _last_ms  = millis();  // Millis returns the number of milliseconds passed since the Arduino board began running the program
}
bool Timer::event()
{ 
  bool result;
  long x= millis();
  bool overflow1= (x < _last_ms);
  bool overflow2= (x - _last_ms > _interval);
  if( overflow1 || overflow2 )
  {
    _last_ms= x;
    result=1;
  } 
  else
  { 
    result=0;
  }
  return result;
}
