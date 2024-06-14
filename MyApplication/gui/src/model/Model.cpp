#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include <touchgfx/Utils.hpp>


Model::Model() : modelListener(0)
{
}

void Model::tick()
{
    canBus.update();
}
