#include "stdafx.h"
#include "Smartphone.h"


Smartphone::Smartphone() {
	setType(1);
}

double Smartphone::getScreenSize() const {
	return screenSize;
}

int Smartphone::getBatteryLife() const {
	return batteryLife;
}

bool Smartphone::getCanRecord4k() const {
	return canRecord4k;
}

void Smartphone::setScreenSize(double screenSize) {
	this->screenSize = screenSize;
}

void Smartphone::setBatteryLife(int batteryLife) {
	this->batteryLife = batteryLife;
}

void Smartphone::setCanRecord4k(bool canRecord4k) {
	this->canRecord4k = canRecord4k;
}