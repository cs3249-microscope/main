#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QPixmap>
#include <QGraphicsScene>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>

#include<QGraphicsScene>
#include <QSplitter>

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    ImageWidget(QWidget *parent = 0);
    QGraphicsPixmapItem *picture; //Modify this with setPixmap anywhere to change picture. Ideally put QInputList object here in public as well.
    void toggleSplitView(QWidget *widget, bool toggledOn);
    void populateScene();
    
signals:
    void imageDepthChanged(int);
    
private:
    void setupMatrix();
    void createDepthSlider();

    QGraphicsScene *scene;
    QSplitter *h1Splitter;
    QSplitter *h2Splitter;
    QSlider *depthSlider;
    QStringList *depthList;
    QVBoxLayout *layout;
    QHBoxLayout *depthLayout;
    QLabel *depthSliderLabel;

public slots:
    void Focus();
    void changeImageDepth(int);
};

#endif //IMAGEWIDGET_H
