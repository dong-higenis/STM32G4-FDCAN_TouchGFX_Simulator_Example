#ifndef SERIAL_HPP
#define SERIAL_HPP

#ifdef SIMULATOR

//#define _USE_THREAD

#include <iostream>
#include <thread>
#include <stdint.h>
#include <windows.h>
#include <stdio.h>


class Serial
{
public:
    Serial();    
    ~Serial()
    {
#ifdef _USE_THREAD
        StopThread();
#endif        
    }
    void update();

#ifdef _USE_THREAD
    static DWORD WINAPI ThreadStaticEntryPoint(LPVOID lpParam) {
        Serial* pThis = static_cast<Serial*>(lpParam);
        if (pThis != nullptr) {
            return pThis->RxThreadFunc();
        }
        return 1;
    }
    DWORD RxThreadFunc(void);
    void StopThread() {
        stopThread_ = true;
    }
#endif

    bool open();
    void sendMsg(uint32_t id, uint8_t *dat, uint8_t len);
protected:  

#ifdef _USE_THREAD
    bool stopThread_;
    HANDLE threadHandle_;
#endif        
};

#endif   
#endif // SERIAL_HPP
