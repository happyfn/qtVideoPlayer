#include "myButton.h"
#include <QWidget>
#include <QDebug>

myButton::myButton(QWidget* parent)
    :QPushButton(parent)
    , m_shadow(new QGraphicsDropShadowEffect(this))
{
    this->initBtn();
}

void myButton::initBtn()
{
    m_shadow->setBlurRadius(10);
    m_shadow->setColor("#151013");
    m_shadow->setOffset(3, 7);
    this->setGraphicsEffect(m_shadow);
    this->setContentsMargins(1, 1, 1, 1);
}

void myButton::mousePressEvent(QMouseEvent* evt)
{
    this->m_shadow->setBlurRadius(0);
    m_shadow->setOffset(0, 0);
    QPushButton::mousePressEvent(evt);
}

void myButton::mouseReleaseEvent(QMouseEvent* evt)
{
    this->m_shadow->setBlurRadius(10);
    m_shadow->setOffset(3, 7);
    QPushButton::mouseReleaseEvent(evt);
}