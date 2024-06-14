#include "bsp.h"
#include "uart.h"

void delay(uint32_t ms)
{
  uint32_t pre_time;

  pre_time = millis();
  while(1)
  {
    if (millis()-pre_time >= ms)
    {
      break;
    }
  }
}


#if defined (__WIN32__) || (__WIN64__)
uint32_t millis(void)
{
  double ret;

  LARGE_INTEGER freq, counter;

  QueryPerformanceCounter(&counter);
  QueryPerformanceFrequency(&freq);

  ret = (double)counter.QuadPart / (double)freq.QuadPart * 1000.0;

  return (uint32_t)ret;
}

uint32_t micros(void)
{
  LARGE_INTEGER freq, counter;
  double ret;

  QueryPerformanceCounter(&counter);
  QueryPerformanceFrequency(&freq);

  ret = (double)counter.QuadPart / (double)freq.QuadPart * 1000000.0;

  return (uint32_t)ret;
}
#else

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>
#include <sys/ioctl.h>


uint32_t millis(void)
{
  double ret;

  LARGE_INTEGER freq, counter;

  QueryPerformanceCounter(&counter);
  QueryPerformanceFrequency(&freq);

  ret = (double)counter.QuadPart / (double)freq.QuadPart * 1000.0;

  return (uint32_t)ret;
}
#endif


