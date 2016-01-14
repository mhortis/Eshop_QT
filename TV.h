#pragma once
#include "ProductBase.h"

class TV : public ProductBase {
public:
	TV();
	double getScreenSize() const;
	bool getCanShow3d() const;
	int getType() { return 2; }
	void setScreenSize(double screenSize);
	void setCanShow3d(bool canShow3d);
private:
	double screenSize;
	bool canShow3d;
};
