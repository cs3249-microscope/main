// main.cpp

#include <QApplication>
#include "PreviewViewer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PreviewViewer previewViewer;
    previewViewer.show();
    return app.exec();
}