
#include <arduino.h>

#ifndef _timer_h
#define _timer_h

class Timer //class nya bernama Timer
{
public:
  Timer(long interval = 100);   // fungsi Timer dengan variabel interval bernilai 100
  void interval(long x);        // fungsi bernama interval yang membutuhkan variabel x jenis long
  bool event();                 // fungsi boolean bernama event
private:
  long _last_ms;
  long _interval;
};

#endif
