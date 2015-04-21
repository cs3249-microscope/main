#include "view.h"
#include "ImageWidget.h"

#include <QHBoxLayout>
#include <QSplitter>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDir>


ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent)
{
    //picture = new QGraphicsPixmapItem();
    depthList = new QStringList();
    depthList->append(QDir::currentPath()+"/PreviewDepth/layer1.png");
    depthList->append(QDir::currentPath()+"/PreviewDepth/layer2.png");
    depthList->append(QDir::currentPath()+"/PreviewDepth/layer3.png");
    depthList->append(QDir::currentPath()+"/PreviewDepth/layer4.png");
    depthList->append(QDir::currentPath()+"/PreviewDepth/layer5.png");
    populateScene();
    createDepthSlider();
    connect(depthSlider, SIGNAL(valueChanged(int)), this, SLOT(Focus()));

    h1Splitter = new QSplitter;
    h2Splitter = new QSplitter;

    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Vertical);
    vSplitter->addWidget(h1Splitter);
    vSplitter->addWidget(h2Splitter);
    View *view = new View("Main view");
        view->view()->setScene(scene);
        h1Splitter->addWidget(view);

        layout = new QVBoxLayout;
        layout->addWidget(vSplitter);
        layout->addWidget(depthSlider);
        setLayout(layout);
}

void ImageWidget::populateScene()
{
    scene = new QGraphicsScene;
    QImage image(QDir::currentPath()+"/PreviewDepth/layer1.png");
    picture = scene->addPixmap(QPixmap::fromImage(image));
}

void ImageWidget::createDepthSlider()
{
    depthSlider = new QSlider;
    depthSlider->setOrientation(Qt::Horizontal);
    depthSlider->setMinimum(0);
    depthSlider->setMaximum(4);
    depthSlider->setValue(0);
    depthSlider->setTickPosition(QSlider::TicksBelow);
}

void ImageWidget::Focus()
{
    QImage image(depthList->at(depthSlider->value()));
    picture->setPixmap(QPixmap::fromImage(image));
    scene->update();
}

void ImageWidget::toggleSplitView(QWidget *widget, bool toggledOn)
{
    if(toggledOn)
    h1Splitter->addWidget(widget);
    else
    {
      delete widget;
    }
}
