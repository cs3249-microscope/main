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
    inputList = new QStringList();
    inputList->append(QDir::currentPath()+"/download.jpg"); //In main/Build right now. Path of executable.
    inputList->append(QDir::currentPath()+"/file.jpeg");
    inputList->append(QDir::currentPath()+"/stuff.jpg");
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
    QImage image(QDir::currentPath()+"/download.jpg");
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
    QString blah = QDir::currentPath();
    qDebug(blah.toLatin1());
    QImage image(inputList->at(depthSlider->value()));
    picture->setPixmap(QPixmap::fromImage(image));
    scene->update();
}
