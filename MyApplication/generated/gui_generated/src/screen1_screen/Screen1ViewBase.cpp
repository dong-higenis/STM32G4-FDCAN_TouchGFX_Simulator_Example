/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase() :
    buttonCallback(this, &Screen1ViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    btnSendMsg.setXY(0, 154);
    btnSendMsg.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_MEDIUM_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_MEDIUM_ROUNDED_PRESSED_ID));
    btnSendMsg.setLabelText(touchgfx::TypedText(T___SINGLEUSE_H8T5));
    btnSendMsg.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    btnSendMsg.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    btnSendMsg.setAction(buttonCallback);
    add(btnSendMsg);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &btnSendMsg)
    {
        //Interaction1
        //When btnSendMsg clicked call virtual function
        //Call funcSendMsg
        funcSendMsg();
    }
}
