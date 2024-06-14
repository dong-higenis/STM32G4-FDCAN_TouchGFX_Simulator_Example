#ifndef MODEL_HPP
#define MODEL_HPP

#include <gui/model/canbus.hpp>

#ifdef SIMULATOR
    #include <windows.h>
    #include <stdio.h>
#endif

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    
    void sendCanMsg(uint32_t id, uint8_t *dat, uint8_t len)
    {
        canBus.sendMsg(id, dat, len);
    }
protected:
    ModelListener* modelListener;

#ifdef SIMULATOR
    HANDLE hSerial;
#endif   
    CanBus canBus;
};

#endif // MODEL_HPP
