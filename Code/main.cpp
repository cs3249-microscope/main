// Name: Bob Wong
// Matric No: A0094718U

// main.cpp

#include <QApplication>
#include "ImageWidget.h"
#include "PreviewViewer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PreviewViewer pviewer;
    pviewer.show();
    return app.exec();
}
