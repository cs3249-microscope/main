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
#include <QAction>
#include <QMenu>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QPlainTextEdit>


class PreviewViewer: public QMainWindow
{
    Q_OBJECT

public:
    PreviewViewer();
    ~PreviewViewer();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void changeExposure();
    void sharpen();
    void magnify();

private:
    void createWidgets();
    void createActions();
    void createMenus();

    QAction *previewAction;
    QAction *startCaptureAction;
    QAction *openPastScansAction;
    QAction *exitAction;
    QAction *toggleViewAction;

    QStringList *exposureList;
    QStringList *magList;

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
	ImageWidget *imageWidget;
    QString currFolder;

};

#endif
