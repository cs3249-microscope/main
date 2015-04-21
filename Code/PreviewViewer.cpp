// PreviewViewer.cpp

#include <QtGui>
#include "PreviewViewer.h"
#include <QScrollArea>

// Constructor

PreviewViewer::PreviewViewer()
{
    layout = new QHBoxLayout();
    leftLayout = new QVBoxLayout();
    createWidgets();
    createSettings();
    createActions();
    createMenus();
    leftLayout->addLayout(bottomLeftLayout);
    layout->addLayout(leftLayout);
    layout->addLayout(rightLayout);
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
    imageWidget = new ImageWidget;
    //imageWidget->setImage("/file.jpeg");
    QVBoxLayout* settings2Layout = new QVBoxLayout;
    //settings2Layout->addWidget(imageWidget);
    QGroupBox* testBox = new QGroupBox;
    testBox->setLayout(settings2Layout);
    testBox->setMinimumSize(800, 800);
    leftLayout->addWidget(imageWidget);

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


    toggledOn = false;
    toggleViewAction = new QAction(tr("&ToggleView"), this);
    toggleViewAction -> setShortcut(tr("Ctrl+V"));
    ///// connection to toggle the tab view.
    connect(toggleViewAction, SIGNAL(triggered()), this, SLOT(toggleView()));


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
    layersLayout = new QVBoxLayout;
    checkBoxLayout = new QVBoxLayout;
    exposureLayout = new QVBoxLayout;
    layersLayout -> addWidget(layerDepthLabel);
    layersLayout -> addWidget(layerDepth);
    checkBoxLayout -> addWidget(autoFocus);
    exposureLayout -> addWidget(exposureLabel);
    exposureLayout -> addWidget(exposureSpinBox);
    exposureLayout->addWidget(exposureSlider);
    layersLayout->addWidget(deltaZLabel);
    layersLayout->addWidget(deltaZ);
    checkBoxLayout -> addWidget(autoWhiteBalance);
    bottomLeftLayout = new QHBoxLayout;
    bottomLeftLayout -> addLayout(layersLayout);
    bottomLeftLayout -> addLayout(checkBoxLayout);
    bottomLeftLayout -> addLayout(exposureLayout);

    settingsGroupBox -> setLayout(settingsLayout);
    settingsGroupBox->setFixedSize(200, 100);
    preview = new QPushButton(tr("Preview"));
    startCapture = new QPushButton(tr("Start capture"));
    openPastScans = new QPushButton(tr("Open Past Scans"));



/////    layout -> addWidget(imageWidget);
    rightLayout -> addWidget(magnificationGroupBox);
    rightLayout -> addWidget(settingsGroupBox);
    rightLayout -> addWidget(preview);
    rightLayout -> addWidget(startCapture);
    rightLayout -> addWidget(openPastScans);

}

void PreviewViewer::toggleView()
{
    toggledOn = !toggledOn;
    if(toggledOn == true)
    {
    autoWhiteBalance = new QCheckBox(tr("AutoWhiteBalance"));
    }
    imageWidget->toggleSplitView(autoWhiteBalance, toggledOn);
}




