// Gallery.h

#ifndef Gallery_H
#define Gallery_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QListWidgetItem>

// class declaration
class QImage;

class Gallery: public QWidget
{
    Q_OBJECT

public:
    Gallery(QString);
    Gallery();

protected:
    
signals:
    void imageDepthChanged(int);
    
private slots:
    void changeImageDepth(QListWidgetItem *, QListWidgetItem *);
    void changeImageDepth(int);
    
    
private:

    void setUpFileList(QStringList listOfFiles);
    void showFiles();

    // Widgets and variables

    QList<QListWidgetItem *> widgetItemList;

    QVector<QImage> fileList;
    int currentImageDepth;

};

#endif
