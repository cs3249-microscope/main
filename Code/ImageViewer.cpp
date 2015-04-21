// ImageViewer.cpp

#include <QtGui>
#include <QWidget>
#include "ImageViewer.h"


ImageViewer::ImageViewer(QString folderName)
{
    currFolder = folderName;
    
    imageWidget = new ImageWidget;
    imageWidget->populateScene();
    gallery = new Gallery(folderName);
    
    QVBoxLayout *layout = new QVBoxLayout;
    layout -> addWidget(imageWidget);
    layout -> addWidget(gallery);
    
    this -> setLayout(layout);
}

void ImageViewer::createConnections()
{
    
    connect(imageWidget, SIGNAL(imageDepthChanged(int)),
            gallery, SLOT(changeImageDepth(int)));
    
    connect(gallery, SIGNAL(imageDepthChanged(int)),
            imageWidget, SLOT(Focus(int)));

}
