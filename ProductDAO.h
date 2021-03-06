#pragma once
#include "ProductBase.h"
#include "PC.h"
#include "Smartphone.h"
#include "TV.h"
#include "Availability.h"
#include "QtSql/QtSql"

class ProductDAO
{
public:
    ProductDAO(QSqlDatabase database);
	int insertProductInDB(PC product, int availability);
	int insertProductInDB(Smartphone product, int availability);
	int insertProductInDB(TV product, int availability);
	int updateProductInDB(PC updatedProduct);
	int updateProductInDB(Smartphone updatedProduct);
	int updateProductInDB(TV updatedProduct);
	int updateProductItemsInDB(int serial, int availability);
	int removeProductFromDB(int serial);
	int removeProductItemsFromDB(int serial, int removedItems);
	int addProductItemsInDB(int serial, int addedItems);
	int getProductAvailabilityFromDB(int serial);
	Availability fetchProductBySerialFromDB(int serial);
    PC fetchPCDetailsFromDB(int serial);
    Smartphone fetchSmartphoneDetailsFromDB(int serial);
    TV fetchTVDetailsFromDB(int serial);
    vector<Availability> fetchProductsByManufacturer(string manufacturer);
	vector<Availability> fetchAllProductsFromDB();
	vector<Availability> fetchAllPCsFromDB();
	vector<Availability> fetchAllSmartphonesFromDB();
	vector<Availability> fetchAllTVsFromDB();
    vector<string> fetchAllManufacturers();
private:
    QSqlDatabase db;
};

