#ifndef Q_DRAW_GRAPHICS_VIEW_H
#define Q_DRAW_GRAPHICS_VIEW_H

#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMouseEvent>

class QDrawGraphicsView : public QGraphicsView {
    Q_OBJECT

public:
    QDrawGraphicsView(QWidget* parent = nullptr);
    void setImage(const QImage& image);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    qreal getScaleFactor();

private:
    QGraphicsScene* scene;
    QPointF startPoint;
    QGraphicsRectItem* currentRect;
    QSize originalImageSize;

public:
    QRectF timePos;
};

#endif