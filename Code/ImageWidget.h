#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QPixmap>
#include <QGraphicsScene>

class QGraphicsScene;
class QSplitter;

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    ImageWidget(QWidget *parent = 0);
    QGraphicsPixmapItem *picture;

private:
    void setupMatrix();
    void populateScene();
    void createDepthSlider();

    QGraphicsScene *scene;
    QSplitter *h1Splitter;
    QSplitter *h2Splitter;
    QSlider *depthSlider;
    QStringList *inputList;

public slots:
    void Focus();

};

#endif //IMAGEWIDGET_H
