//MicroscopeAPI.cpp

#include "MicroscopeAPI.h"

MicroscopeAPI::Microscope() {
//add those image files here!
}

int MicroscopeAPI::getXLength() {
	return 60;
}

int MicroscopeAPI::getYLength() {
	return 60;
}

void MicroscopeAPI::setFocalLength(double fl) {
	focalLength = fl;
}

double MicroscopeAPI::getFocalLength() {
	return focalLength;
}

void MicroscopeAPI::setMagnification(double mag){
	magnification = mag;
}

double MicroscopeAPI::getMagnification(){
	return magnification;
}

void MicroscopeAPI::setExposure(double exp){
	exposure = exp;
}

double MicroscopeAPI::getExposure(){
	return exposure;
}

void MicroscopeAPI::toggleAutoFocus(){
	autoFocus = !autoFocus;
}

bool MicroscopeAPI::getAutoFocus(){
	return autoFocus;
}

void MicroscopeAPI::toggleAutoWhiteBalance(){
	autoWhiteBalance = !autoWhiteBalance;
}

bool MicroscopeAPI::getAutoWhiteBalance(){
	return autoWhiteBalance;
}

QString MicroscopeAPI::upDepth(int exp) {
	if (depth>=5)
		return "";
	depth += 1.0;
	
	switch ((int)depth) {
	case 1:
		return depth2[exp];
	case 2:
		return depth3[exp];
	case 3:
		return depth4[exp];
	case 4:
		return depth5[exp];
	default:
		return "";
	}
}

QString MicroscopeAPI::downDepth(int exp){
	if (depth<=1)
		return "";
	depth -= 1.0;
	
	switch ((int)depth) {
	case 5:
		return depth4[exp];
	case 2:
		return depth1[exp];
	case 3:
		return depth2[exp];
	case 4:
		return depth3[exp];
	default:
		return "";
	}
}

QString MicroscopeAPI::upExposure(int depth){
	if (exposure>=5)
		return "";
	exposure += 1.0;
	
	switch (depth) {
	case 1:
		return depth1[(int)exposure];
	case 2:
		return depth2[(int)exposure];
	case 3:
		return depth3[(int)exposure];
	case 4:
		return depth4[(int)exposure];
	case 5:
		return depth5[(int)exposure];
	default:
		return "";
	}
}

QString MicroscopeAPI::downExposure(int depth){
		if (exposure<=1)
		return "";
	exposure -= 1.0;
	
	switch (depth) {
	case 1:
		return depth1[(int)exposure];
	case 2:
		return depth2[(int)exposure];
	case 3:
		return depth3[(int)exposure];
	case 4:
		return depth4[(int)exposure];
	case 5:
		return depth5[(int)exposure];
	default:
		return "";
	}
}