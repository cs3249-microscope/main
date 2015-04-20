// PreviewViewer.cpp

#include <QtGui>
#include "PreviewViewer.h"
#include <QScrollArea>

// Constructor

PreviewViewer::PreviewViewer()
{
    layout = new QHBoxLayout();
        createWidgets();
    createSettings();
    createActions();
    createMenus();
    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
}

PreviewViewer::~PreviewViewer()
{
/////    delete imageViewer;
/////    delete imageWidget;
}

// Protected methods

void PreviewViewer::closeEvent(QCloseEvent *event)
{
/////    imageViewer->close();
}

// Create widgets, actions, menus.

void PreviewViewer::createWidgets()
{
    ImageWidget *imageWidget = new ImageWidget;
    imageWidget->setImage("/file.jpeg");
    imageWidget->setMinimumSize(800, 800);
    imageWidget->setMaximumSize(800, 800);
    QVBoxLayout* settings2Layout = new QVBoxLayout;
    settings2Layout->addWidget(imageWidget);

    QGroupBox* testBox = new QGroupBox;
    testBox->setLayout(settings2Layout);
    layout->addWidget(testBox);

/////    setCentralWidget(imageWidget);


    // create ImageViewer widget
/////    imageViewer = new ImageViewer();

}

void PreviewViewer::createActions()
{

    previewAction = new QAction(tr("&Preview"), this);
    previewAction -> setShortcut(tr("Ctrl+P"));
    previewAction -> setStatusTip(tr("Set to start preview"));
    ///// connection to microscope here

    startCaptureAction = new QAction(tr("&StartCapture"), this);
    startCaptureAction -> setShortcut(tr("Ctrl+C"));
    startCaptureAction -> setStatusTip(tr("Capture the photos"));
    ///// connection to microscope here


    openPastScansAction = new QAction(tr("&OpenPastScans"), this);
    openPastScansAction -> setShortcut(tr("Ctrl+O"));
    openPastScansAction -> setStatusTip(tr("See previous scans"));
/////    connect(openPastScansAction, SIGNAL(triggered()), imageViewer, SLOT(show()));


    exitAction = new QAction(tr("&Exit"), this);
    exitAction -> setShortcut(tr("Ctrl+Q"));
    exitAction -> setStatusTip(tr("Exit PreviewViewer"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));


    toggleViewAction = new QAction(tr("&ToggleView"), this);
    toggleViewAction -> setShortcut(tr("Ctrl+V"));
    ///// connection to toggle the tab view.


    // Other connections
    connect(exposureSpinBox, SIGNAL(valueChanged(int)), exposureSlider, SLOT(setValue(int)));
    connect(exposureSlider, SIGNAL(valueChanged(int)), exposureSpinBox, SLOT(setValue(int)));

}

void PreviewViewer::createMenus()
{
    fileMenu = menuBar() -> addMenu(tr("&File"));
    fileMenu -> addAction(previewAction);
    fileMenu -> addAction(startCaptureAction);
    fileMenu -> addAction(openPastScansAction);
    fileMenu -> addSeparator();
    fileMenu -> addAction(exitAction);
    menuBar() -> addAction(toggleViewAction);
}

void PreviewViewer::createSettings()
{
//    // settings
    rightLayout = new QVBoxLayout();
    magnificationGroupBox = new QGroupBox(tr("Lens/Magnification"));
    magnificationLabel = new QLabel(tr("&Magnification"));
    magnification = new QSpinBox;
    ///// magnification -> setRange(0, 300);
    magnificationLabel -> setBuddy(magnification);
    magLayout = new QHBoxLayout;
    magLayout -> addWidget(magnificationLabel);
    magLayout -> addWidget(magnification);
    magnificationGroupBox -> setLayout(magLayout);
    magnificationGroupBox -> setMaximumSize(200, 100);


    settingsGroupBox = new QGroupBox(tr("Settings"));
//    ///// save location

    autoFocus = new QCheckBox(tr("Auto Focus"));
    autoWhiteBalance = new QCheckBox(tr("Auto White Balance"));

    layerDepthLabel = new QLabel(tr("Layer depth"));
    layerDepth = new QSpinBox;
    ///// layerDepth -> setRange(i ,j);
    layerDepthLabel -> setBuddy(layerDepth);

    deltaZLabel = new QLabel(tr("∂z"));
    deltaZ = new QSpinBox;
//    ///// deltaZ -> setRange(i, j)
    deltaZLabel -> setBuddy(deltaZ);

    exposureLabel = new QLabel(tr("Exposure"));
    exposureSpinBox = new QSpinBox;
    ////// exposureSpinBox -> setRange(i, j);
    exposureLabel -> setBuddy(exposureSpinBox);
    exposureSlider = new QSlider(Qt::Horizontal);
    //////exposureSlider -> setRange(i, j);

    settingsLayout = new QHBoxLayout;
    settingsLayout -> addWidget(autoFocus);
    settingsLayout -> addWidget(autoWhiteBalance);
    settingsLayout -> addWidget(layerDepthLabel);
    settingsLayout -> addWidget(layerDepth);
    settingsLayout -> addWidget(deltaZLabel);
    settingsLayout -> addWidget(deltaZ);
    settingsLayout -> addWidget(exposureLabel);
    settingsLayout -> addWidget(exposureSpinBox);
    settingsLayout -> addWidget(exposureSlider);
    settingsGroupBox -> setLayout(settingsLayout);
    settingsGroupBox->setFixedSize(500, 100);
    preview = new QPushButton(tr("Preview"));
    startCapture = new QPushButton(tr("Start capture"));
    openPastScans = new QPushButton(tr("Open Past Scans"));



/////    layout -> addWidget(imageWidget);
    rightLayout -> addWidget(magnificationGroupBox);
    rightLayout -> addWidget(settingsGroupBox);
    rightLayout -> addWidget(preview);
    rightLayout -> addWidget(startCapture);
    rightLayout -> addWidget(openPastScans);
    layout->addLayout(rightLayout);
    //QWidget *window = new QWidget;

    //this->setLayout(layout);
    //window->show();

}






