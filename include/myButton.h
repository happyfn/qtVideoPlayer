#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <QGraphicsDropShadowEffect>
#include <QPushButton>
#include <QMouseEvent>

class myButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myButton(QWidget* parent = nullptr);

private:

    void initBtn();
    void mousePressEvent(QMouseEvent* evt);
    void mouseReleaseEvent(QMouseEvent* evt);
private:

    QGraphicsDropShadowEffect* m_shadow;

};

#endif

