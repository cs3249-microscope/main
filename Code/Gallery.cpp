// Gallery.cpp

#include <QtGui>
#include <QListWidget>
#include <QListWidgetItem>
#include <QWidget>
#include "Gallery.h"

// Constructor


Gallery::Gallery(QString folderName)
{
    
    // get all files from folder
    QDir *fileDir = new QDir(folderName);
    QStringList listOfFiles = fileDir->entryList(QStringList("*.png" "*.jpg"),
                                                 QDir::Files,
                                                 QDir::Name);
    
    
    widgetItemList = QList<QListWidgetItem *>();
    setUpFileList(listOfFiles);
    showFiles();
}

Gallery::Gallery()
{
    
}

void Gallery::setUpFileList(QStringList listOfFiles)
{
    // Some error checking on the format of the files.
    
    
    

//    // get list of files and merge into image.
    
//    QString last = listOfFiles.at(listOfFiles.size()-1);
//    QString depthlayer = last.split("-").at(0);
//    bool ok;
//    int numLayers = depthlayer.toInt(&ok, 10);
//    for (int i = 0; i < numLayers; ++i) {
//        for (int i = 0; i < listOfFiles.size()/numLayers; i++) {
//        
////            QPixmap mergedImage(width, height);
////            QPainter painter(&mergedImage);
//        
//        }
//    
//
//    }
    
//    // create and show thumbnails of all files
//    for (int i = 0; i < listOfFiles.size(); ++i) {
//        QIcon img = QIcon(listOfFiles.at(i));
//        
//        // scale into thumbnail
//        img.scaled(200, 200, Qt::IgnoreAspectRatio, Qt::FastTransformation).scaled(100, 100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    
//        
//    }
//    
//    
//    currentImageDepth = 0;
    

    
}

void Gallery::showFiles() {
    
//    QGridLayout *galleryLayout = new QGridLayout();
//    
//    // show thumbnails here
//    for (int i = 0; i < fileList.size(); ++i) {
//        
//        QLabel *picture = new QLabel;
//        QPixmap pixmap;
//        pixmap.convertFromImage(fileList.at(i), 0);
//        picture -> setPixmap(pixmap);
//        
//        galleryLayout -> addWidget(picture, i/4, i %4);
//        
//        //// show active selection
//        if (i == currentImageDepth) {
//            
//        }
//    }
//
//    this -> setLayout(galleryLayout);
    
    QHBoxLayout *galleryLayout = new QHBoxLayout();
    
    QListWidget *listWidget = new QListWidget;
    listWidget -> setViewMode(QListWidget::IconMode);
    listWidget -> setResizeMode(QListWidget::Adjust);
    listWidget -> setSelectionMode(QAbstractItemView::SingleSelection);

    listWidget -> setMaximumSize(800, 40);
    QListWidgetItem *itm  = new QListWidgetItem();
    itm->setIcon(QIcon(QDir::currentPath()+"/thumbnails/t1.png"));
    listWidget -> addItem(itm);
    itm  = new QListWidgetItem();
    itm->setIcon(QIcon(QDir::currentPath()+"/thumbnails/t2.png"));
    listWidget -> addItem(itm);
    itm  = new QListWidgetItem();
    itm->setIcon(QIcon(QDir::currentPath()+"/thumbnails/t3.png"));
    listWidget -> addItem(itm);
    itm  = new QListWidgetItem();
    itm->setIcon(QIcon(QDir::currentPath()+"/thumbnails/t4.png"));
    listWidget -> addItem(itm);
    itm  = new QListWidgetItem();
    itm->setIcon(QIcon(QDir::currentPath()+"/thumbnails/t5.png"));
    listWidget -> addItem(itm);

    
    
    
    widgetItemList = listWidget -> findItems("pic", Qt::MatchStartsWith);
//    listWidget -> addItem(new QListWidgetItem(QIcon(mergedImageList->at(0)), "pic1"));
//    listWidget -> addItem(new QListWidgetItem(QIcon(mergedImageList->at(1)), "pic2"));
    
    
    galleryLayout -> addWidget(listWidget);
    this -> setLayout(galleryLayout);

    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onListItemClicked(QListWidgetItem*)));

    
    //connect(listWidget, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)),
           // this, SLOT(changeImageDepth(QListWidgetItem *, QListWidgetItem *)));
//
//    



    
    
}


void Gallery::changeImageDepth(QListWidgetItem *curr, QListWidgetItem *prev) {
    
    //    if (currentImageDepth != depth) {
    //        currentImageDepth = depth;
    //        QImage currFile = fileList.at(depth);
    //
    //        //// change the active selection indication here.
    //
    //
    
    int depth = widgetItemList.indexOf(curr);
    
    
    emit imageDepthChanged(depth);
}

void Gallery::changeImageDepth(int depth) {
    
        if (currentImageDepth != depth) {
            currentImageDepth = depth;
//            QImage currFile = fileList.at(depth);
            
    
            //// change the active selection indication here.
    
    
    
    
    
    emit imageDepthChanged(depth);
}
}

