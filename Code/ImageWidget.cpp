#include "view.h"
#include "ImageWidget.h"

#include <QHBoxLayout>
#include <QSplitter>
#include <QPixmap>


ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent)
{
    populateScene();

    h1Splitter = new QSplitter;
    h2Splitter = new QSplitter;

    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Vertical);
    vSplitter->addWidget(h1Splitter);
    vSplitter->addWidget(h2Splitter);

    View *view = new View("Main view");
        view->view()->setScene(scene);
        h1Splitter->addWidget(view);

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(vSplitter);
        setLayout(layout);

        setWindowTitle(tr("Chip Example"));
}

void ImageWidget::populateScene()
{
    scene = new QGraphicsScene;
    QImage image("/file.jpeg");
    scene->addPixmap(QPixmap::fromImage(image));
}
