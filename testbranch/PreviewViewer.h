// PreviewViewer.h

#ifndef PREVIEWVIEWER_H
#define PREVIEWVIEWER_H

#include <QMainWindow>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "ImageWidget.h"
// #include "ImageViewer.h"

// Class declaration without loading .h files. Faster compilation.
class QAction;
class QMenu;
class QGroupBox;
class QPushButton;
class QCheckBox;
class QPlainTextEdit;


class PreviewViewer: public QMainWindow
{
    Q_OBJECT

public:
    PreviewViewer();
    ~PreviewViewer();

protected:
    void closeEvent(QCloseEvent *event);

private slots:

private:
    void createWidgets();
    void createActions();
    void createMenus();

    QAction *previewAction;
    QAction *startCaptureAction;
    QAction *openPastScansAction;
    QAction *exitAction;
    QAction *toggleViewAction;

    QMenu *fileMenu;

    // settings
    QPushButton *preview;
    QPushButton *startCapture;
    QPushButton *openPastScans;

    QCheckBox *autoFocus;
    QCheckBox *autoWhiteBalance;

    QSpinBox *exposureSpinBox;
    QSpinBox *deltaZ;
    QSpinBox *layerDepth;
    QSpinBox *magnification;

    QSlider *exposureSlider;

    // Widgets and variables
    // ImageViewer *imageViewer;
	ImageWidget *imageWidget;
    QString currFolder;

};

#endif