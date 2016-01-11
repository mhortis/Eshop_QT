#include "stdafx.h"
#include "PC.h"

PC::PC() {
	setType(0);
}

int PC::getRam() const {
	return this->ram;
}

double PC::getCpu() const {
	return this->cpu;
}

string PC::getDiskType() const {
	return this->diskType;
}

int PC::getDiskSpace() const {
	return this->diskSpace;
}

string PC::getGpu() const {
	return this->gpu;
}

void PC::setRam(int ram) {
	this->ram = ram;
}

void PC::setCpu(double cpu) {
	this->cpu = cpu;
}

void PC::setDiskType(const char* diskType) {
    this->diskType = string(diskType);
}

void PC::setDiskSpace(int diskSpace) {
	this->diskSpace = diskSpace;
}

void PC::setGpu(const char* gpu) {
    this->gpu = string(gpu);
}
