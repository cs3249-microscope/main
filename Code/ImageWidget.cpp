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
    scene = new QGraphicsScene;
    QImage image(QDir::currentPath()+"/blank.png");
    picture = scene->addPixmap(QPixmap::fromImage(image));
    createDepthSlider();
    connect(depthSlider, SIGNAL(valueChanged(int)), this, SLOT(Focus(int)));
    connect(depthSlider, SIGNAL(valueChanged(int)), this, SIGNAL(imageDepthChanged(int)));

    h1Splitter = new QSplitter;
    h2Splitter = new QSplitter;

    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Vertical);
    vSplitter->addWidget(h1Splitter);
    //vSplitter->addWidget(h2Splitter);
    View *view = new View("Main view");
        view->view()->setScene(scene);
        h1Splitter->addWidget(view);

        layout = new QVBoxLayout;
        layout->addWidget(vSplitter);
        layout->addLayout(depthLayout);
        setLayout(layout);
}

void ImageWidget::populateScene()
{
    scene = new QGraphicsScene;
    QImage image(QDir::currentPath()+"/PreviewDepth/layer1.png");
    picture->setPixmap(QPixmap::fromImage(image));
}

void ImageWidget::createDepthSlider()
{
    depthLayout = new QHBoxLayout();
    depthSliderLabel = new QLabel(tr("Depth"));
    depthSlider = new QSlider;
    depthSlider->setOrientation(Qt::Horizontal);
    depthSlider->setMinimum(0);
    depthSlider->setMaximum(4);
    depthSlider->setValue(0);
    depthSlider->setTickPosition(QSlider::TicksBelow);
    depthLayout->addWidget(depthSliderLabel);
    depthLayout->addWidget(depthSlider);
}

void ImageWidget::Focus(int newDepth)
{
    QImage image(depthList->at(newDepth));
    picture->setPixmap(QPixmap::fromImage(image));
    scene->update();
}

void ImageWidget::changeImageDepth(int depth) {
	if ( depthSlider->value()!=depth )
		depthSlider->setValue(depth);
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

