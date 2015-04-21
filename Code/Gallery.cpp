// Gallery.cpp

#include <QtGui>
#include <QWidget>
#include "Gallery.h"

// Constructor

Gallery::Gallery(QStringList listOfFiles)
{
    setUpFileList(listOfFiles);
}

void setUpFileList(QStringList listOfFiles)
{
    fileList = listOfFiles;
    
    // create and show thumbnails of all files
    for (int i = 0; i < fileList.size(); ++i) {
        QImage img(fileList.at(i));
        
        //// scale into thumbnail here
        
        
        
        fileList.append(img);
    }
    
    //// show the thumbnails here
    
    
}


void changeImageDepth(int depth) {
    
    if (currentImageDepth != depth) {
        currentImageDepth = depth;
        currFile = fileList.at(depth);
        
        //// change the active selection indication here.
        
        
        
        emit imageDepthChanged(depth);
    }
    
    
}