// ImageWidget.cpp
#include <QtGui>
#include <QGraphicsTextItem>
#include <QTextStream>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "ImageWidget.h"

ImageWidget::ImageWidget(QWidget *parent): QWidget(parent) {
	QHBoxLayout *topLayout = new QHBoxLayout;
	QHBoxLayout *bottomLayout = new QHBoxLayout;
	QVBoxLayout *fullLayout = new QVBoxLayout;

	createWidgets();

	topLayout->addWidget(imageViewer);//imageviewer
	topLayout->addWidget(zoomSlider);//VSlider
	bottomLayout->addWidget(depthSlider);//HSlider
	//bottomLayout->addWidget();//???

	fullLayout->addLayout(topLayout);
	fullLayout->addLayout(bottomLayout);
	this->setLayout(fullLayout);

	// Set defaults
	zoom = 0.1;
	depth = 1;
	setMinimumSize(10, 10); // width, height
}

void ImageWidget::setImageSet(const QList<QPixmap> &imageSet) {
	for(int i=0;i<imageSet.size();++i){
		inputList.append(imageSet[i]);
	}
	scene->addPixmap(inputList[0]);
}

//public slots: slot to get change in depth (made by the gallery)
void ImageWidget::changeDepth(int valueFromSlider) {	
	setImage(valueFromSlider);
}

//private slots: only by use of private sliders
void ImageWidget::changeZoom(int valueFromSlider) {
	setZoom(valueFromSlider/10.0);
}

//protected
void ImageWidget::wheelEvent(QWheelEvent *event) {
	imageViewer->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

	float newZoom = zoom;	
	if (event->delta()>0) {
		newZoom = zoom+0.1;
	}
	else if ( event->delta()<0 ) {
		newZoom = zoom-0.1;
	}
	char string[100];
	sprintf(string, "%.1f", newZoom);
	sscanf(string, "%f", &newZoom); // rounding
	setZoom(newZoom);
}

//private methods
void ImageWidget::createWidgets() {
	zoomSlider = new QSlider(Qt::Vertical);
	zoomSlider->setMinimum(10);
	zoomSlider->setMaximum(1000);
	depthSlider = new QSlider(Qt::Horizontal);
	depthSlider->setMinimum(1);
	depthSlider->setMaximum(inputList.size());
	
	scene = new QGraphicsScene;
	imageViewer->setScene(scene);

	//connect sliders to mainwidget
	connect(this, SIGNAL(zoomChanged(int)), zoomSlider, SLOT(setValue(int)));
	connect(this, SIGNAL(depthChanged(int)), depthSlider, SLOT(setValue(int)));
	connect(zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(changeZoom(int)));
	connect(depthSlider, SIGNAL(valueChanged(int)), this, SLOT(changeDepth(int)));
}

void ImageWidget::setZoom(float newZoom) {
	if (newZoom == zoom)//if there is no change in zoom
		return;	
	if (newZoom <= 0.0)
		return; // no change

	//QSize newSize = newZoom * input.size();
	//if (newSize.width() < minimumWidth() || newSize.height() < minimumHeight() || newSize.width() > maximumWidth() || newSize.height() > maximumHeight())
	//	return; // no change
	
	imageViewer->scale(newZoom/zoom,newZoom/zoom);
	zoom = newZoom;
	qDebug("zoom %f", zoom); // for debugging
	emit zoomChanged((int)zoom*10);
}

void ImageWidget::setImage(int imageNumber) {
/*	QImage image = QImage(fileName); // Get image
	QPixmap input = QPixmap::fromImage(image); // For display

	//if image is larger than initsize, scale down image to fit
	//if image is smaller than initsize, scale up image to fit 
	// Determine appropriate initial zoom

	float initWidth = size().width();
	float initHeight = size().height();
	float wRatio = (float) initWidth / (float) input.width();
	float hRatio = (float) initHeight / (float) input.height();
	float initZoom = qMin(wRatio, hRatio);
	qDebug("initZoom %f", initZoom);
	if (initZoom >= 1.0)
	initZoom = 1.0; // Use original size if possible.
	setZoom(initZoom);*/
	
	//remove scene?
	depth = imageNumber;
	currDisplay->setPixmap(inputList[imageNumber]);
}
