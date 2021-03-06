// PreviewViewer.cpp

#include <QtGui>
#include <QWidget>
#include "PreviewViewer.h"

// Constructor

PreviewViewer::PreviewViewer()
{
    createWidgets();
    createActions();
    createMenus();

}

PreviewViewer::~PreviewViewer()
{
/////    delete imageViewer;
 //   delete imageWidget;
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


    // create ImageViewer widget
/////    imageViewer = new ImageViewer();


    // settings

    QGroupBox *magnificationGroupBox = new QGroupBox(tr("Lens/ Magnification"));
    QLabel *magnificationLabel = new QLabel(tr("&Magnification"));
    magnification = new QSpinBox;
    ///// magnification -> setRange(0, 300);
    magnificationLabel -> setBuddy(magnification);
    
    QHBoxLayout *magLayout = new QHBoxLayout;
    magLayout -> addWidget(magnificationLabel);
    magLayout -> addWidget(magnification);
    magnificationGroupBox -> setLayout(magLayout);


    QGroupBox *settingsGroupBox = new QGroupBox(tr("Settings"));
    ///// save location


    autoFocus = new QCheckBox(tr("Auto Focus"));
    autoWhiteBalance = new QCheckBox(tr("Auto White Balance"));
    
	QHBoxLayout *checkbox = new QHBoxLayout;
	checkbox -> addWidget(autoFocus);
	checkbox -> addWidget(autoWhiteBalance);

    
    QLabel *layerDepthLabel = new QLabel(tr("Layer depth"));
    layerDepth = new QSpinBox;
    ///// layerDepth -> setRange(i ,j);
    
    QLabel *deltaZLabel = new QLabel(tr("∂z"));
    deltaZ = new QSpinBox;
    ///// deltaZ -> setRange(i, j)

	QGridLayout *depthLayout = new QGridLayout;
	depthLayout -> addWidget(layerDepthLabel, 0, 0);
	depthLayout -> addWidget(layerDepth, 0, 1);
	depthLayout -> addWidget(deltaZLabel, 1, 0);
	depthLayout -> addWidget(deltaZ, 1, 1);
    

    QLabel *exposureLabel = new QLabel(tr("Exposure"));
    exposureSpinBox = new QSpinBox;
exposureSpinBox -> setRange(0, 99);
    exposureSlider = new QSlider(Qt::Horizontal);
exposureSlider -> setRange(0, 99);

    QHBoxLayout *exposureLabelSpinBox = new QHBoxLayout;
    exposureLabelSpinBox -> addWidget(exposureLabel);
    exposureLabelSpinBox -> addWidget(exposureSpinBox);
    
	QVBoxLayout *exposureLayout= new QVBoxLayout;
    exposureLayout -> addLayout(exposureLabelSpinBox);
    exposureLayout -> addWidget(exposureSlider);

    
    QVBoxLayout *settingsLayout = new QVBoxLayout;
    settingsLayout -> addLayout(checkbox);
    settingsLayout -> addLayout(depthLayout);
    settingsLayout -> addLayout(exposureLayout);
    settingsGroupBox -> setLayout(settingsLayout);
    

    preview = new QPushButton(tr("Preview"));
    startCapture = new QPushButton(tr("Start capture"));
    openPastScans = new QPushButton(tr("Open past scans"));


	QVBoxLayout *vlayout = new QVBoxLayout;
	vlayout -> addWidget(magnificationGroupBox);
    vlayout -> addWidget(settingsGroupBox);
    vlayout -> addWidget(preview);
    vlayout -> addWidget(startCapture);
    vlayout -> addWidget(openPastScans);


    QHBoxLayout *layout = new QHBoxLayout;
    layout -> addWidget(imageWidget);
    layout -> addLayout(vlayout);

    
    QWidget *window = new QWidget();
    window -> setLayout(layout);
    	
    
    setCentralWidget(window);
}

void PreviewViewer::createActions()
{
// 
     previewAction = new QAction(tr("&Preview"), this);
     previewAction -> setShortcut(tr("Ctrl+P"));
     previewAction -> setStatusTip(tr("Set to start preview"));
//     ///// connection to microscope here
// 
     startCaptureAction = new QAction(tr("&StartCapture"), this);
     startCaptureAction -> setShortcut(tr("Ctrl+C"));
     startCaptureAction -> setStatusTip(tr("Capture the photos"));
//     ///// connection to microscope here
// 
// 
     openPastScansAction = new QAction(tr("&OpenPastScans"), this);
     openPastScansAction -> setShortcut(tr("Ctrl+O"));
     openPastScansAction -> setStatusTip(tr("See previous scans"));
// /////    connect(openPastScansAction, SIGNAL(triggered()), imageViewer, SLOT(show()));
// 
// 
     exitAction = new QAction(tr("&Exit"), this);
     exitAction -> setShortcut(tr("Ctrl+Q"));
     exitAction -> setStatusTip(tr("Exit PreviewViewer"));
     connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
//
// 
     toggleViewAction = new QAction(tr("&ToggleView"), this);
     toggleViewAction -> setShortcut(tr("Ctrl+V"));
//     ///// connection to toggle the tab view.
// 
// 
//     // Other connections
     connect(exposureSpinBox, SIGNAL(valueChanged(int)), exposureSlider, SLOT(setValue(int)));
     connect(exposureSlider, SIGNAL(valueChanged(int)), exposureSpinBox, SLOT(setValue(int)));
//

}

void PreviewViewer::createMenus()
{
     fileMenu = menuBar() -> addMenu(tr("&File"));
     fileMenu -> addAction(previewAction);
     fileMenu -> addAction(startCaptureAction);
     fileMenu -> addAction(openPastScansAction);
     fileMenu -> addSeparator();
     fileMenu -> addAction(exitAction);

//     QMenu *viewMenu = menuBar() -> addMenu(tr("&View"));
    menuBar() -> addAction(toggleViewAction);
}
