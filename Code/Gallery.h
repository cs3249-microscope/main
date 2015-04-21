// Gallery.h

#ifndef Gallery_H
#define Gallery_H

#include <QWidget>

// class declaration
class QImage;

class Gallery: public QWidget
{
    Q_OBJECT

public:
    Gallery(QString);
    ~Gallery();

protected:
    
signals:
    void imageDepthChanged(int);
    
private slots:
    void changeImageDepth(int);
    
private:

    void setUpFileList(QStringList listOfFiles);
    void showFiles();

    // Widgets and variables

    QVector<QImage> fileList;
    int currentImageDepth;

};

#endif