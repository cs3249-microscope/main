// ImageViewer.h

#ifndef ImageViewer_H
#define ImageViewer_H

#include <QWidget>
#include <QVBoxLayout>
#include "ImageWidget.h"
#include "Gallery.h"


class ImageViewer: public QWidget
{
    Q_OBJECT

public:
    ImageViewer(QString folderName);

protected:
    

private slots:
    void createConnections();
    
private:

    // Widgets and variables
	ImageWidget *imageWidget;
    Gallery *gallery;
    QString currFolder;

};

#endif