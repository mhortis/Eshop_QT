#include "stdafx.h"
#include "ProductDAO.h"

ProductDAO::ProductDAO(QSqlDatabase database) {
	db = database;
}

int ProductDAO::insertProductInDB(PC product, int availability) {
    if (!db.open()) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

    QSqlQuery query;

    query.prepare("insert into products (TYPE, PRICE, MODEL, MANUFACTURER, " \
		"PHOTOURL, DESCRIPTION, RAM, CPU, DISKTYPE, DISKSPACE, GPU, " \
		"AVAILABILITY)"
        "values(0, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");

    query.addBindValue(product.getPrice());
    query.addBindValue(QString::fromStdString(product.getModel()));
    query.addBindValue(QString::fromStdString(product.getManufacturer()));
    query.addBindValue(QString::fromStdString(product.getPhotoUrl()));
    query.addBindValue(QString::fromStdString(product.getDescription()));
    query.addBindValue(product.getRam());
    query.addBindValue(product.getCpu());
    query.addBindValue(QString::fromStdString(product.getDiskType()));
    query.addBindValue(product.getDiskSpace());
    query.addBindValue(QString::fromStdString(product.getGpu()));
    query.addBindValue(availability);

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in insertion of new PC. Error code: %d\n", query.lastError());
        return false;
    }
}

int ProductDAO::insertProductInDB(Smartphone product, int availability) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("insert into products (TYPE, PRICE, MODEL, MANUFACTURER, " \
		"PHOTOURL, DESCRIPTION, SCREENSIZE, BATTERYLIFE, CANRECORD4K, " \
		"AVAILABILITY)"
        "values(1, ?, ?, ?, ?, ?, ?, ?, ?, ?);");

    query.addBindValue(product.getPrice());
    query.addBindValue(QString::fromStdString(product.getModel()));
    query.addBindValue(QString::fromStdString(product.getManufacturer()));
    query.addBindValue(QString::fromStdString(product.getPhotoUrl()));
    query.addBindValue(QString::fromStdString(product.getDescription()));
    query.addBindValue(product.getScreenSize());
    query.addBindValue(product.getBatteryLife());
    query.addBindValue(product.getCanRecord4k());
    query.addBindValue(availability);

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in insertion of new Smartphone. Error code: %d\n", query.lastError());
        return false;
    }
}

int ProductDAO::insertProductInDB(TV product, int availability) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("insert into products (TYPE, PRICE, MODEL, MANUFACTURER, " \
		"PHOTOURL, DESCRIPTION, SCREENSIZE, CANSHOW3D, AVAILABILITY)" \
        "values(2, ?, ?, ?, ?, ?, ?, ?, ? )");

    query.addBindValue(product.getPrice());
    query.addBindValue(QString::fromStdString(product.getModel()));
    query.addBindValue(QString::fromStdString(product.getManufacturer()));
    query.addBindValue(QString::fromStdString(product.getPhotoUrl()));
    query.addBindValue(QString::fromStdString(product.getDescription()));
    query.addBindValue(product.getScreenSize());
    query.addBindValue(product.getCanShow3d());
    query.addBindValue(availability);

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in insertion of new TV. Error code: %d\n", query.lastError());
        return false;
    }
}

int ProductDAO::updateProductInDB(PC updatedProduct) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("update products set PRICE = ?, MODEL = ?, " \
		"MANUFACTURER = ?, PHOTOURL = ?, DESCRIPTION = ?, RAM = ?, CPU = ?, " \
        "DISKTYPE = ?, DISKSPACE = ?, GPU = ? WHERE SERIAL = ?");
    query.addBindValue(updatedProduct.getPrice());
    query.addBindValue(QString::fromStdString(updatedProduct.getModel()));
    query.addBindValue(QString::fromStdString(updatedProduct.getManufacturer()));
    query.addBindValue(QString::fromStdString(updatedProduct.getPhotoUrl()));
    query.addBindValue(QString::fromStdString(updatedProduct.getDescription()));
    query.addBindValue(updatedProduct.getRam());
    query.addBindValue(updatedProduct.getCpu());
    query.addBindValue(QString::fromStdString(updatedProduct.getDiskType()));
    query.addBindValue(updatedProduct.getDiskSpace());
    query.addBindValue(QString::fromStdString(updatedProduct.getGpu()));
    query.addBindValue(updatedProduct.getSerial());

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in update of PC. Error code: %d\n", query.lastError());
        return false;
    }
}

int ProductDAO::updateProductInDB(Smartphone updatedProduct) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("update products set PRICE = ?, MODEL = ?, " \
		"MANUFACTURER = ?, PHOTOURL = ?, DESCRIPTION = ?, SCREENSIZE = ?, " \
        "BATTERYLIFE = ?, CANRECORD4K = ? WHERE SERIAL = ?");

    query.addBindValue(updatedProduct.getPrice());
    query.addBindValue(QString::fromStdString(updatedProduct.getModel()));
    query.addBindValue(QString::fromStdString(updatedProduct.getManufacturer()));
    query.addBindValue(QString::fromStdString(updatedProduct.getPhotoUrl()));
    query.addBindValue(QString::fromStdString(updatedProduct.getDescription()));
    query.addBindValue(updatedProduct.getScreenSize());
    query.addBindValue(updatedProduct.getBatteryLife());
    query.addBindValue(updatedProduct.getCanRecord4k());
    query.addBindValue(updatedProduct.getSerial());

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in update of Smartphone. Error code: %d\n", query.lastError());
        return false;
    }
}

int ProductDAO::updateProductInDB(TV updatedProduct) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("update products set PRICE = ?, MODEL = ?, " \
		"MANUFACTURER = ?, PHOTOURL = ?, DESCRIPTION = ?, " \
        "SCREENSIZE = ?, CANSHOW3D = ? WHERE SERIAL = ?");

    query.addBindValue(updatedProduct.getPrice());
    query.addBindValue(QString::fromStdString(updatedProduct.getModel()));
    query.addBindValue(QString::fromStdString(updatedProduct.getManufacturer()));
    query.addBindValue(QString::fromStdString(updatedProduct.getPhotoUrl()));
    query.addBindValue(QString::fromStdString(updatedProduct.getDescription()));
    query.addBindValue(updatedProduct.getScreenSize());
    query.addBindValue(updatedProduct.getCanShow3d());
    query.addBindValue(updatedProduct.getSerial());

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in update of TV. Error code: %d\n", query.lastError());
        return false;
    }
}

int ProductDAO::updateProductItemsInDB(int serial, int availability) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("update in products set AVAILABILITY = ? where SERIAL = ?");

    query.addBindValue(availability);
    query.addBindValue(serial);

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in update of product. Error code: %d\n", query.lastError());
        return false;
    }
}

int ProductDAO::removeProductFromDB(int serial) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("delete from products where SERIAL = ?");

    query.addBindValue(serial);

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in removal of product. Error code: %d\n", query.lastError());
        return false;
    }
}

int ProductDAO::removeProductItemsFromDB(int serial, int removedItems) {
	int productAvailability = getProductAvailabilityFromDB(serial);
	productAvailability -= removedItems;
	int res = updateProductItemsInDB(serial, productAvailability);

	return res;
}

int ProductDAO::addProductItemsInDB(int serial, int addedItems) {
	int productAvailability = getProductAvailabilityFromDB(serial);
	productAvailability += addedItems;
	int res = updateProductItemsInDB(serial, productAvailability);

	return res;
}

int ProductDAO::getProductAvailabilityFromDB(int serial) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("select AVAILABILITY from products where SERIAL = ?");

    query.addBindValue(serial);

    if(query.exec()){
        if(query.next()){
            int idName = query.record().indexOf("AVAILABILITY");
            int availability = query.value(idName).toInt();
            return availability;
        }
        else{
            fprintf(stderr, "No product found for availability. Error code: %d\n", query.lastError());
            return false;
        }
    }
    else{
        fprintf(stderr, "Error in getting product availability. Error code: %d\n", query.lastError());
        return false;
    }
}

Availability ProductDAO::fetchProductBySerialFromDB(int serial) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        Availability avail;
        return avail;
    }

    QSqlQuery query;

    query.prepare("SELECT * from products where SERIAL=?");
    query.addBindValue(serial);

    if(query.exec()){
        if(query.next()){
            if(query.value(query.record().indexOf("TYPE")) == 0){
                PC fetchedProduct = PC();
                fetchedProduct.setSerial(query.value(query.record().indexOf("SERIAL")).toInt());
                fetchedProduct.setModel(query.value(query.record().indexOf("MODEL")).toString().toLocal8Bit().constData());
                fetchedProduct.setManufacturer(query.value(query.record().indexOf("MANUFACTURER")).toString().toLocal8Bit().constData());
                fetchedProduct.setPhotoUrl(query.value(query.record().indexOf("PHOTOURL")).toString().toLocal8Bit().constData());
                fetchedProduct.setDescription(query.value(query.record().indexOf("DESCRIPTION")).toString().toLocal8Bit().constData());
                fetchedProduct.setRam(query.value(query.record().indexOf("RAM")).toInt());
                fetchedProduct.setCpu(query.value(query.record().indexOf("CPU")).toDouble());
                fetchedProduct.setDiskType(query.value(query.record().indexOf("DISKTYPE")).toString().toLocal8Bit().constData());
                fetchedProduct.setDiskSpace(query.value(query.record().indexOf("DISKSPACE")).toInt());
                fetchedProduct.setGpu(query.value(query.record().indexOf("GPU")).toString().toLocal8Bit().constData());
                int availability = query.value(query.record().indexOf("AVAILABILITY")).toInt();
                Availability avail(fetchedProduct, availability);
                return avail;
            }
            else if(query.value(query.record().indexOf("TYPE")) == 1){
                Smartphone fetchedProduct = Smartphone();
                fetchedProduct.setSerial(query.value(query.record().indexOf("SERIAL")).toInt());
                fetchedProduct.setModel(query.value(query.record().indexOf("MODEL")).toString().toLocal8Bit().constData());
                fetchedProduct.setManufacturer(query.value(query.record().indexOf("MANUFACTURER")).toString().toLocal8Bit().constData());
                fetchedProduct.setPhotoUrl(query.value(query.record().indexOf("PHOTOURL")).toString().toLocal8Bit().constData());
                fetchedProduct.setDescription(query.value(query.record().indexOf("DESCRIPTION")).toString().toLocal8Bit().constData());
                fetchedProduct.setScreenSize(query.value(query.record().indexOf("SCREENSIZE")).toDouble());
                fetchedProduct.setBatteryLife(query.value(query.record().indexOf("BATTERYLIFE")).toInt());
                fetchedProduct.setCanRecord4k(query.value(query.record().indexOf("CANRECORD4K")).toBool());
                int availability = query.value(query.record().indexOf("AVAILABILITY")).toInt();
                Availability avail(fetchedProduct, availability);
                return avail;
            }
            else {
                TV fetchedProduct = TV();
                fetchedProduct.setSerial(query.value(query.record().indexOf("SERIAL")).toInt());
                fetchedProduct.setModel(query.value(query.record().indexOf("MODEL")).toString().toLocal8Bit().constData());
                fetchedProduct.setManufacturer(query.value(query.record().indexOf("MANUFACTURER")).toString().toLocal8Bit().constData());
                fetchedProduct.setPhotoUrl(query.value(query.record().indexOf("PHOTOURL")).toString().toLocal8Bit().constData());
                fetchedProduct.setDescription(query.value(query.record().indexOf("DESCRIPTION")).toString().toLocal8Bit().constData());
                fetchedProduct.setScreenSize(query.value(query.record().indexOf("SCREENSIZE")).toDouble());
                fetchedProduct.setCanShow3d(query.value(query.record().indexOf("CANSHOW3D")).toBool());
                int availability = query.value(query.record().indexOf("AVAILABILITY")).toInt();
                Availability avail(fetchedProduct, availability);
                return avail;
            }
        }
        else{
            fprintf(stderr, "Error in fetching product by serial. Error code: %d\n", query.lastError());
            Availability avail;
            return avail;

        }
    }
    else{
        fprintf(stderr, "Error in fetching product by serial. Error code: %d\n", query.lastError());
        Availability avail;
        return avail;
    }
}

vector<Availability> ProductDAO::fetchAllProductsFromDB() {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        vector<Availability> avail;
        return avail;
    }

    QSqlQuery query;
    vector <Availability> products;

    query.prepare("SELECT * from products;");

    if(query.exec()){
        while(query.next()){
            if(query.value(query.record().indexOf("TYPE")) == 0){
                PC fetchedProduct = PC();
                fetchedProduct.setSerial(query.value(query.record().indexOf("SERIAL")).toInt());
                fetchedProduct.setModel(query.value(query.record().indexOf("MODEL")).toString().toLocal8Bit().constData());
                fetchedProduct.setManufacturer(query.value(query.record().indexOf("MANUFACTURER")).toString().toLocal8Bit().constData());
                fetchedProduct.setPhotoUrl(query.value(query.record().indexOf("PHOTOURL")).toString().toLocal8Bit().constData());
                fetchedProduct.setDescription(query.value(query.record().indexOf("DESCRIPTION")).toString().toLocal8Bit().constData());
                fetchedProduct.setRam(query.value(query.record().indexOf("RAM")).toInt());
                fetchedProduct.setCpu(query.value(query.record().indexOf("CPU")).toDouble());
                fetchedProduct.setDiskType(query.value(query.record().indexOf("DISKTYPE")).toString().toLocal8Bit().constData());
                fetchedProduct.setDiskSpace(query.value(query.record().indexOf("DISKSPACE")).toInt());
                fetchedProduct.setGpu(query.value(query.record().indexOf("GPU")).toString().toLocal8Bit().constData());
                int availability = query.value(query.record().indexOf("AVAILABILITY")).toInt();
                Availability avail(fetchedProduct, availability);
                products.push_back(avail);
            }
            else if(query.value(query.record().indexOf("TYPE")) == 1){
                Smartphone fetchedProduct = Smartphone();
                fetchedProduct.setSerial(query.value(query.record().indexOf("SERIAL")).toInt());
                fetchedProduct.setModel(query.value(query.record().indexOf("MODEL")).toString().toLocal8Bit().constData());
                fetchedProduct.setManufacturer(query.value(query.record().indexOf("MANUFACTURER")).toString().toLocal8Bit().constData());
                fetchedProduct.setPhotoUrl(query.value(query.record().indexOf("PHOTOURL")).toString().toLocal8Bit().constData());
                fetchedProduct.setDescription(query.value(query.record().indexOf("DESCRIPTION")).toString().toLocal8Bit().constData());
                fetchedProduct.setScreenSize(query.value(query.record().indexOf("SCREENSIZE")).toDouble());
                fetchedProduct.setBatteryLife(query.value(query.record().indexOf("BATTERYLIFE")).toInt());
                fetchedProduct.setCanRecord4k(query.value(query.record().indexOf("CANRECORD4K")).toBool());
                int availability = query.value(query.record().indexOf("AVAILABILITY")).toInt();
                Availability avail(fetchedProduct, availability);
                products.push_back(avail);
            }
            else if(query.value(query.record().indexOf("TYPE")) == 2){
                TV fetchedProduct = TV();
                fetchedProduct.setSerial(query.value(query.record().indexOf("SERIAL")).toInt());
                fetchedProduct.setModel(query.value(query.record().indexOf("MODEL")).toString().toLocal8Bit().constData());
                fetchedProduct.setManufacturer(query.value(query.record().indexOf("MANUFACTURER")).toString().toLocal8Bit().constData());
                fetchedProduct.setPhotoUrl(query.value(query.record().indexOf("PHOTOURL")).toString().toLocal8Bit().constData());
                fetchedProduct.setDescription(query.value(query.record().indexOf("DESCRIPTION")).toString().toLocal8Bit().constData());
                fetchedProduct.setScreenSize(query.value(query.record().indexOf("SCREENSIZE")).toDouble());
                fetchedProduct.setCanShow3d(query.value(query.record().indexOf("CANSHOW3D")).toBool());
                int availability = query.value(query.record().indexOf("AVAILABILITY")).toInt();
                Availability avail(fetchedProduct, availability);
                products.push_back(avail);
            }
        }
    }
    else{
        fprintf(stderr, "Error in fetching products from database. Error code: %d\n", query.lastError());
        vector<Availability> avail;
        return avail;
    }

    return products;
}

vector<Availability> ProductDAO::fetchAllPCsFromDB() {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        vector<Availability> avail;
        return avail;
    }

    QSqlQuery query;
    vector <Availability> products;

    query.prepare("SELECT * from products where TYPE=0");

    if(query.exec()){
        while(query.next()){
            PC fetchedProduct = PC();
            fetchedProduct.setSerial(query.value(query.record().indexOf("SERIAL")).toInt());
            fetchedProduct.setModel(query.value(query.record().indexOf("MODEL")).toString().toLocal8Bit().constData());
            fetchedProduct.setManufacturer(query.value(query.record().indexOf("MANUFACTURER")).toString().toLocal8Bit().constData());
            fetchedProduct.setPhotoUrl(query.value(query.record().indexOf("PHOTOURL")).toString().toLocal8Bit().constData());
            fetchedProduct.setDescription(query.value(query.record().indexOf("DESCRIPTION")).toString().toLocal8Bit().constData());
            fetchedProduct.setRam(query.value(query.record().indexOf("RAM")).toInt());
            fetchedProduct.setCpu(query.value(query.record().indexOf("CPU")).toDouble());
            fetchedProduct.setDiskType(query.value(query.record().indexOf("DISKTYPE")).toString().toLocal8Bit().constData());
            fetchedProduct.setDiskSpace(query.value(query.record().indexOf("DISKSPACE")).toInt());
            fetchedProduct.setGpu(query.value(query.record().indexOf("GPU")).toString().toLocal8Bit().constData());
            int availability = query.value(query.record().indexOf("AVAILABILITY")).toInt();
            Availability avail(fetchedProduct, availability);
            products.push_back(avail);
        }
    }
    else{
        fprintf(stderr, "Error in fetching PCs from database. Error code: %d\n", query.lastError());
        vector<Availability> avail;
        return avail;
    }

    return products;
}

vector<Availability> ProductDAO::fetchAllSmartphonesFromDB() {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        vector<Availability> avail;
        return avail;
    }

    QSqlQuery query;
    vector <Availability> products;

    query.prepare("SELECT * from products where TYPE=1");

    if(query.exec()){
        while(query.next()){
            Smartphone fetchedProduct = Smartphone();
            fetchedProduct.setSerial(query.value(query.record().indexOf("SERIAL")).toInt());
            fetchedProduct.setModel(query.value(query.record().indexOf("MODEL")).toString().toLocal8Bit().constData());
            fetchedProduct.setManufacturer(query.value(query.record().indexOf("MANUFACTURER")).toString().toLocal8Bit().constData());
            fetchedProduct.setPhotoUrl(query.value(query.record().indexOf("PHOTOURL")).toString().toLocal8Bit().constData());
            fetchedProduct.setDescription(query.value(query.record().indexOf("DESCRIPTION")).toString().toLocal8Bit().constData());
            fetchedProduct.setScreenSize(query.value(query.record().indexOf("SCREENSIZE")).toDouble());
            fetchedProduct.setBatteryLife(query.value(query.record().indexOf("BATTERYLIFE")).toInt());
            fetchedProduct.setCanRecord4k(query.value(query.record().indexOf("CANRECORD4K")).toBool());
            int availability = query.value(query.record().indexOf("AVAILABILITY")).toInt();
            Availability avail(fetchedProduct, availability);
            products.push_back(avail);
        }
    }
    else{
        fprintf(stderr, "Error in fetching Smartphones from database. Error code: %d\n", query.lastError());
        vector<Availability> avail;
        return avail;
    }
    return products;
}

vector<Availability> ProductDAO::fetchAllTVsFromDB() {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        vector<Availability> avail;
        return avail;
    }

    QSqlQuery query;
    vector <Availability> products;

    query.prepare("SELECT * from products where TYPE=2");

    if(query.exec()){
        while(query.next()){
            TV fetchedProduct = TV();
            fetchedProduct.setSerial(query.value(query.record().indexOf("SERIAL")).toInt());
            fetchedProduct.setModel(query.value(query.record().indexOf("MODEL")).toString().toLocal8Bit().constData());
            fetchedProduct.setManufacturer(query.value(query.record().indexOf("MANUFACTURER")).toString().toLocal8Bit().constData());
            fetchedProduct.setPhotoUrl(query.value(query.record().indexOf("PHOTOURL")).toString().toLocal8Bit().constData());
            fetchedProduct.setDescription(query.value(query.record().indexOf("DESCRIPTION")).toString().toLocal8Bit().constData());
            fetchedProduct.setScreenSize(query.value(query.record().indexOf("SCREENSIZE")).toDouble());
            fetchedProduct.setCanShow3d(query.value(query.record().indexOf("CANSHOW3D")).toBool());
            int availability = query.value(query.record().indexOf("AVAILABILITY")).toInt();
            Availability avail(fetchedProduct, availability);
            products.push_back(avail);
        }
    }
    else{
        fprintf(stderr, "Error in fetching TVs from database. Error code: %d\n", query.lastError());
        vector<Availability> avail;
        return avail;
    }
    return products;
}