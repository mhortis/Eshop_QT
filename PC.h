#pragma once
#include "ProductBase.h"

class PC : public ProductBase {
public:
	PC();
	int getRam() const;
	double getCpu() const;
    string getDiskType() const;
	int getDiskSpace() const;
    string getGpu() const;
	int getType() { return 0; }
	void setRam(int ram);
	void setCpu(double cpu);
    void setDiskType(const char* diskType);
	void setDiskSpace(int diskSpace);
    void setGpu(const char* gpu);
private:
	int ram;
	double cpu;
    string diskType;
	int diskSpace;
    string gpu;
};
