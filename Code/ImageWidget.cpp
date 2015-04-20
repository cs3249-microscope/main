#include "view.h"
#include "ImageWidget.h"

#include <QHBoxLayout>
#include <QSplitter>
#include <QPixmap>
#include <QGraphicsPixmapItem>


ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent)
{
    inputList = new QStringList();
    inputList->append("/file.jpeg");
    inputList->append("/download.jpeg");
    inputList->append("/stuff2.jpg");
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

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(vSplitter);
        layout->addWidget(depthSlider);
        setLayout(layout);
}

void ImageWidget::populateScene()
{
    scene = new QGraphicsScene;
    QImage image("/file.jpeg");
    picture = scene->addPixmap(QPixmap::fromImage(image));
}

void ImageWidget::createDepthSlider()
{
    depthSlider = new QSlider;
    depthSlider->setOrientation(Qt::Horizontal);
    depthSlider->setMinimum(0);
    depthSlider->setMaximum(2);
    depthSlider->setValue(0);
    depthSlider->setTickPosition(QSlider::TicksBelow);
}

void ImageWidget::Focus()
{
    qDebug("testing");
    QString blah = inputList->at(depthSlider->value());
    qDebug(blah.toLatin1());
    QImage image(inputList->at(depthSlider->value()));
    picture->setPixmap(QPixmap::fromImage(image));
}
