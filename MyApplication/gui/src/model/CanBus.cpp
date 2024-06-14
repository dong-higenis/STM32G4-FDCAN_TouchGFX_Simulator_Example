#include <gui/model/CanBus.hpp>

#include <touchgfx/Utils.hpp>


CanBus::CanBus()
{ 
#ifdef SIMULATOR
    serial.open();
#endif
}

void CanBus::update()
{
#ifdef SIMULATOR
    serial.update();
#endif
}   

bool CanBus::sendMsg(uint16_t id, uint8_t* dat, uint8_t len)
{
#ifdef SIMULATOR
    serial.sendMsg(id, dat, len);
return true;
#endif
}
