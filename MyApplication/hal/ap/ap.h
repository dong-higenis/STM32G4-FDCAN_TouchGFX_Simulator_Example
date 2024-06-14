#ifndef AP_H_
#define AP_H_


#include "hw_def.h"


void apInit(void);
void apMain(void);
void apSend(uint32_t id, uint8_t* dat, uint8_t len);
#endif
