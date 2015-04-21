// Gallery.cpp

#include <QtGui>
#include <QWidget>
#include "Gallery.h"

// Constructor

Gallery::Gallery(QString folderName)
{
    // get all files from folder
    QDir *fileDir = new QDir(folderName);
    QStringList listOfFiles = fileDir->entryList();
    
    setUpFileList(listOfFiles);
    showFiles();
}

Gallery::Gallery()
{
    
}

void Gallery::setUpFileList(QStringList listOfFiles)
{
    // get list of files and merge into image.
    
    // create and show thumbnails of all files
    for (int i = 0; i < listOfFiles.size(); ++i) {
        QImage img = QImage(listOfFiles.at(i));
        
        // scale into thumbnail
        img.scaled(200, 200, Qt::IgnoreAspectRatio, Qt::FastTransformation).scaled(100, 100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        
        
        //// scale into thumbnail here
        
        
        
        fileList.append(img);
    }
    
    
    currentImageDepth = 0;
}

void Gallery::showFiles() {
    
    QGridLayout *galleryLayout = new QGridLayout();
    
    // show thumbnails here
    for (int i = 0; i < fileList.size(); ++i) {
        
        QLabel *picture = new QLabel;
        QPixmap pixmap;
        pixmap.convertFromImage(fileList.at(i), 0);
        picture -> setPixmap(pixmap);
        
        galleryLayout -> addWidget(picture, i/4, i %4);
        
        //// show active selection
        if (i == currentImageDepth) {
            
        }
    }

    this -> setLayout(galleryLayout);
    

    
    
}


void Gallery::changeImageDepth(int depth) {
    
    if (currentImageDepth != depth) {
        currentImageDepth = depth;
        QImage currFile = fileList.at(depth);
        
        //// change the active selection indication here.
        
        
        
        emit imageDepthChanged(depth);
    }
    
    
}