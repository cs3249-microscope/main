// ImageWidget.h
#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSlider>
#include <QImage>
#include <QPixmap>
#include <vector>

class ImageWidget: public QWidget
{
	Q_OBJECT
	Q_PROPERTY(float zoom READ getZoom WRITE setZoom)
	
public:
	ImageWidget(QWidget *parent = 0);
	void setImageSet(const QList<QPixmap> &imageSet);
	float getZoom() const { return zoom; } // inline
protected:
	void wheelEvent(QWheelEvent *event);
signals:
	void zoomChanged(float newZoom);
	void depthChanged(int newDepth);
public slots:
	void changeDepth(int newDepth);
private slots:
	void changeZoom(int newZoom);
private:
	void createWidgets();
	void setZoom(float newZoom);
	void setImage(int imageNumber);

	QSlider *zoomSlider;
	QSlider *depthSlider;
	QGraphicsScene *scene;
	QGraphicsView *imageViewer;

	//QPoint widgetCenter;
	//QPoint imageCenter;
	QList<QPixmap> inputList; // Input images.
	QGraphicsPixmapItem *currDisplay; //pointer to current displayed layer
	int depth;	
	float zoom;
};
#endif
