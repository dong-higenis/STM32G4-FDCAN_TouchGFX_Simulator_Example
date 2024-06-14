#include <gui/simulator/Serial.hpp>
#include "ap.h"
#ifdef SIMULATOR
#include <touchgfx/Utils.hpp>

#ifdef _USE_THREAD
DWORD Serial::RxThreadFunc(void)
{    
    while (!stopThread_) {       
        apMain();
        Sleep(1);        
    }
    return 0;
}
#endif
Serial::Serial()
{  
#ifdef _USE_THREAD
    stopThread_ = false;
#endif    
}

bool Serial::open()
{  
    apInit();
#ifdef _USE_THREAD    
    threadHandle_ = CreateThread(NULL, 0, &Serial::ThreadStaticEntryPoint, this, 0, NULL);
    if (threadHandle_ == NULL) {
        touchgfx_printf("Failed to create thread!\r\n");
    }
#endif        
    return true;    
}


void Serial::update()
{
#ifndef _USE_THREAD  
    apMain();
#endif    
}

void Serial::sendMsg(uint32_t id, uint8_t *dat, uint8_t len)
{
    apSend(id, dat, len);
}
#endif