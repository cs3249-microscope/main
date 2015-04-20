// Name: Bob Wong
// Matric No: A0094718U

// ImageWidget.cpp

#include <QtGui>
#include "imagewidget.h"

ImageWidget::ImageWidget(QWidget *parent): QWidget(parent)
{
    // Set defaults
    zoom = 0.0;
    setMinimumSize(100, 100);
}

void ImageWidget::setImage(const QString &fileName)
{
    QImage image = QImage(fileName);
    input = QPixmap::fromImage(image);

    // Determine initial zoom
    float initWidth = 800;
    float initHeight = 600;
    float wRatio = (float) initWidth / (float) input.width();
    float hRatio = (float) initHeight / (float) input.height();
    float initZoom = qMin(wRatio, hRatio);

    if (input.width() <= minimumWidth()
    ||  input.height() <= minimumHeight())
    {
        wRatio = (float) minimumWidth() / (float) input.width();
        hRatio = (float) minimumHeight() / (float) input.height();
        initZoom = qMax(wRatio, hRatio);
        setZoom(initZoom);
    }

    if (initZoom >= 1.0)
        initZoom = 1.0;

    setZoom(initZoom);
}

void ImageWidget::setZoom(float newZoom)
{
    if (newZoom <= 0.0)
        return;

    QSize newSize = newZoom * input.size();
    if (
        newSize.width() < minimumWidth() ||
        newSize.height() < minimumHeight() ||
        newSize.width() > maximumWidth() ||
        newSize.height() > maximumHeight())
        return;

    zoom = newZoom;
    display = input.scaled(zoom * input.size(), 			   Qt::KeepAspectRatio);

    resize(display.size());


    qDebug("zoom %f", zoom);
}

// Event handlers
void ImageWidget::paintEvent(QPaintEvent *event)
{
    QRectF rect = QRectF(QPoint(), size());
    QPainter painter(this);
    painter.drawPixmap(rect, display, rect);
}

void ImageWidget::wheelEvent(QWheelEvent *event)
{
    float step = event->delta() / 1200.0;
    float newZoom = zoom + step;
    setZoom(newZoom);
}

void ImageWidget::resizeEvent(QResizeEvent *event){

    float newWidth = width();
    float newHeight = height();

    float wRatio = (float) newWidth / (float) input.width();
    float hRatio = (float) newHeight / (float) input.height();
    float newZoom = qMax(wRatio, hRatio);

    QSize newSize = newZoom * input.size();
    if (newSize.width() < minimumWidth() ||
        newSize.height() < minimumHeight())
        return;

    if(newZoom >= 1.0 && input.width() > minimumWidth() && input.height() > minimumHeight())
    {
        newZoom = 1.0;
    }

    zoom = newZoom;
    display = input.scaled(zoom * input.size(),
                           Qt::KeepAspectRatio);

    qDebug("zoom %f", zoom);
}
