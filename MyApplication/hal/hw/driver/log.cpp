#include "bsp.h"
#include <touchgfx/Utils.hpp>

void logPrintf(const char *fmt, ...)
{
  va_list args;
  char print_buf[256];

  va_start(args, fmt);
  vsnprintf(print_buf, 256, fmt, args);

  touchgfx_printf("%s", print_buf);
  va_end(args);
}
