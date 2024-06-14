#ifndef CAN_BUS_HPP
#define CAN_BUS_HPP

#include <stdint.h>
#ifdef SIMULATOR
    #include "cmd.h"
    #include <gui/simulator/serial.hpp>
#endif

class CanBus
{
public:
    CanBus();    

    void update();
    bool sendMsg(uint16_t id, uint8_t* dat, uint8_t len);

protected:
    

#ifdef SIMULATOR
    
    cmd_t cmd_boot;
    cmd_driver_t cmd_driver;
    Serial serial;
#endif   
};

#endif // CAN_BUS_HPP
