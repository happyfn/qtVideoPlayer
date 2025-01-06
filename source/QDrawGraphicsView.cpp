#include "QDrawGraphicsView.h"
#include "utils.h"
#include <QPixmap>
#include <QDebug>

QDrawGraphicsView::QDrawGraphicsView(QWidget* parent) : QGraphicsView(parent), startPoint(QPointF()), currentRect(nullptr) {
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    scene = new QGraphicsScene(this);   //No need to manually release memory
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void QDrawGraphicsView::setImage(const QImage& image) {
    QPixmap pixmap = QPixmap::fromImage(image);
    originalImageSize = image.size();
    QGraphicsPixmapItem* pixItem = scene->addPixmap(pixmap);
    scene->setSceneRect(0, 0, pixmap.width(), pixmap.height());
    fitInView(pixItem, Qt::KeepAspectRatio);
}

void QDrawGraphicsView::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        startPoint = mapToScene(event->pos());
        if (currentRect) {
            scene->removeItem(currentRect);
            SAFE_DELETE(currentRect);
        }
        currentRect = scene->addRect(QRectF(startPoint, startPoint), QPen(Qt::red), QBrush(Qt::transparent));
    }
}

void QDrawGraphicsView::mouseMoveEvent(QMouseEvent* event) {
    if (currentRect) {
        QPointF currentPoint = mapToScene(event->pos());
        QRectF rect(startPoint, currentPoint);
        currentRect->setRect(rect.normalized());
    }
}

void QDrawGraphicsView::mouseReleaseEvent(QMouseEvent* event) {
    if (currentRect) {
        QRectF rect = currentRect->rect();
        qreal scale = getScaleFactor();
        timePos = QRectF(rect.topLeft() / scale, rect.size() / scale);
    }
}

void QDrawGraphicsView::resizeEvent(QResizeEvent* event) {
    QGraphicsView::resizeEvent(event);

    if (!scene->items().isEmpty()) {
        QGraphicsPixmapItem* pixItem = dynamic_cast<QGraphicsPixmapItem*>(scene->items().first());
        if (pixItem) {
            fitInView(pixItem, Qt::KeepAspectRatio);
        }
    }
}

qreal QDrawGraphicsView::getScaleFactor() {
    QGraphicsPixmapItem* pixItem = dynamic_cast<QGraphicsPixmapItem*>(scene->items().first());
    if (pixItem) {
        qreal scaleX = width() / (qreal)originalImageSize.width();
        qreal scaleY = height() / (qreal)originalImageSize.height();
        return qMin(scaleX, scaleY);
    }
    return 1.0;
}
