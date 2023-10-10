#include "uicontroller.h"

UIController::UIController(QObject *parent)
    : QObject{parent}
{
    m_isButtonClicked = false;
    m_rotation = 0;
}

bool UIController::isButtonClicked() {
    return m_isButtonClicked;
}

int UIController::rotation()
{
    return m_rotation;
}

void UIController::setRotation(bool clockwise) {
    if(clockwise) {
        m_rotation += 10;
    } else {
        m_rotation -= 10;
    }
    m_rotation %= 360;
    emit rotationChanged();
}

void UIController::setIsButtonClicked(bool isButtonClicked) {
    m_isButtonClicked = isButtonClicked;
    emit isButtonClickedChanged();
}

