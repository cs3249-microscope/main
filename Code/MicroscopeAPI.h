// MicroscopeAPI.h

#ifndef MICROSCOPE_API_H
#define MICROSCOPE_API_H
#include <QStringList>

class MicroscopeAPI {

public:
	Microscope();
	int getXLength();
	int getYLength();
	void setFocalLength(double);
	double getFocalLength();
	void setMagnification(double);
	double getMagnification();
	void setExposure(double);
	double getExposure();
	void toggleAutoFocus();
	bool getAutoFocus();
	void toggleAutoWhiteBalance();
	bool getAutoWhiteBalance();
	QString upDepth(int exp);
	QString downDepth(int exp);
	QString upExposure(int depth);
	QString downExposure(int depth);
private:
	double magnification;
	double focalLength;
	double exposure;
	bool autoFocus;
	bool autoWhiteBalance;
	QStringList depth1;
	QStringList depth2;
	QStringList depth3;
	QStringList depth4;
	QStringList depth5;
}