// Gallery.cpp

#include <QtGui>
#include <QWidget>
#include "Gallery.h"

// Constructor

Gallery::Gallery(QStringList listOfFiles)
{
    setUpFileList(listOfFiles);
    showFiles();
}

void setUpFileList(QStringList listOfFiles)
{
    fileList = listOfFiles;
    
    // create and show thumbnails of all files
    for (int i = 0; i < fileList.size(); ++i) {
        QImage img = QImage(fileList.at(i));
        
        // scale into thumbnail
        img.scaled(200, 200, Qt::IgnoreAspectRatio, Qt::FastTransformation).scaled(100, 100, Qt:IgnoreAspectRatio, Qt::SmoothTransformation);
        QImage img(fileList.at(i));
        
        //// scale into thumbnail here
        
        
        
        fileList.append(img);
    }
    
    
    depth = 0;
}

void showFiles() {
    
    QGridLayout *galleryLayout = new QGridLayout();
    
    // show thumbnails here
    for (int i = 0; i < fileList.size(); ++i) {
        
        QLabel picture = new QLabel(i);
        QPixmap pixmap = QPixmap::convertFromImage(fileList.at(i), 0);
        picture.setPixmap(picture);
        
        galleryLayout -> addWidget(QLabel, i/4, i %4);
        
        //// show active selection
        if (i == depth) {
            
        }
    }

    this -> setLayout(galleryLayout);
    

    
    
}


void changeImageDepth(int depth) {
    
    if (currentImageDepth != depth) {
        currentImageDepth = depth;
        currFile = fileList.at(depth);
        
        //// change the active selection indication here.
        
        
        
        emit imageDepthChanged(depth);
    }
    
    
}