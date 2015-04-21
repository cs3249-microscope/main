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
    Gallery();
    ~Gallery();

protected:
    
signals:
    void imageDepthChanged(int);
    
private slots:
    void changeImageDepth(int);
    
private:
    void createWidgets();
    void createActions();

    // Widgets and variables
    QString currFile;
    QVector<QImage> fileList;
    int currentImageDepth;

};

#endif