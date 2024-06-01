#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton(QWidget* parent) :
    QPushButton(parent)
{
    buttonID = ++resID;
}

QDynamicButton::~QDynamicButton()
{

}

int QDynamicButton::GetID()
{
    return buttonID;
}

int QDynamicButton::resID = 0;
