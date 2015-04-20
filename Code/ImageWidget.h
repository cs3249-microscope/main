// Name: Bob Wong
// Matric No: A0094718U

// ImageWidget.h

#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPixmap>

class ImageWidget: public QWidget
{
    Q_OBJECT
    Q_PROPERTY(float zoom READ getZoom WRITE setZoom)

public:
    ImageWidget(QWidget *parent = 0);
    void setImage(const QString &fileName);
    float getZoom() const { return zoom; }
    void setZoom(float newZoom);

protected:
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    QPixmap input;
    QPixmap display;
    float zoom;
};

#endif
