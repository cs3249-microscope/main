#ifndef PREVIEWVIEWER_H
#define PREVIEWVIEWER_H

#include <QMainWindow>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QAction>
#include <QMenu>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QMenuBar>
#include <QLabel>

#include "ImageWidget.h"

class PreviewViewer: public QMainWindow
{
    Q_OBJECT

public:
    PreviewViewer();
    ~PreviewViewer();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void createWidgets();
    void createActions();
    void createMenus();
    void createSettings();
    void createPreviewImage();

    QAction *previewAction;
    QAction *startCaptureAction;
    QAction *openPastScansAction;
    QAction *exitAction;
    QAction *toggleViewAction;

    QMenu *fileMenu;

    //Settings

    QGroupBox *magnificationGroupBox;
    QGroupBox *settingsGroupBox;

    QLabel *layerDepthLabel;
    QLabel *deltaZLabel;
    QLabel *magnificationLabel;
    QLabel *exposureLabel;

    QHBoxLayout *magLayout;
    QHBoxLayout *settingsLayout;
    QHBoxLayout *layout;

    QVBoxLayout *rightLayout;

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

    QString currFolder;
};

#endif // PREVIEWVIEWER_H

