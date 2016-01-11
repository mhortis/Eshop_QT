#pragma once
using namespace std;

class ProductBase
{
public:
	ProductBase();
	int getSerial() const;
	virtual int getType()
	{ return type; }
    string getModel();
    string getManufacturer();
    string getPhotoUrl();
    string getDescription();
	double getPrice();
	void setSerial(int serial);
	void setType(int type);
    void setModel(const char* model);
    void setManufacturer(const char* manufacturer);
    void setPhotoUrl(const char* photoUrl);
    void setDescription(const char* description);
	void setPrice(double price);
	bool operator== (const ProductBase &p2) const;
	bool operator< (const ProductBase &p2) const;
	bool operator> (const ProductBase &p2) const;
private:
	int serial;
	int type;
    string model;
    string manufacturer;
    string photoUrl;
    string description;
	double price;
};

