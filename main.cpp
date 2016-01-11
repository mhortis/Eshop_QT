#include "mainwindow.h"
#include <QApplication>
#include "QtSql/QtSql"
#include "ProductDAO.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QSqlDatabase m_db;

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName( QDir::homePath() + QDir::separator() + "people.db");
    if (!m_db.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << QDir::homePath() + QDir::separator() + "people.db";
       qDebug() << "Database: connection ok";
    }

    QSqlQuery query(m_db);
    if (query.exec("CREATE TABLE PRODUCTS("  \
                  "SERIAL INTEGER PRIMARY KEY AUTOINCREMENT     NOT NULL," \
                  "TYPE   INTEGER                 NOT NULL," \
                  "PRICE  REAL				NOT NULL," \
                  "MODEL	TEXT				NOT NULL," \
                  "MANUFACTURER	TEXT		NOT NULL," \
                  "PHOTOURL		TEXT," \
                  "DESCRIPTION	TEXT," \
                  "RAM			INTEGER," \
                  "CPU			REAL," \
                  "DISKTYPE		TEXT," \
                  "DISKSPACE		INTEGER," \
                  "GPU			TEXT," \
                  "SCREENSIZE		REAL," \
                  "BATTERYLIFE	INTEGER," \
                  "CANRECORD4K	INTEGER," \
                  "CANSHOW3D		INTEGER," \
                  "AVAILABILITY   INTEGER );")){
        qDebug() << "Successfully created table.";
    }
    else{
        qDebug() << "Did not create products table.";
    }


    ProductDAO productDao = ProductDAO(m_db);

    PC product1 = PC();
    product1.setPrice(599.99);
    product1.setModel("gs60");
    product1.setManufacturer("msi");
    product1.setPhotoUrl("msi.jpg");
    product1.setDescription("laptop msi gs60 2qe 226nl 4k edition 156 intel i7 4720hq 16gb 2x128gb 1tb gtx970m 3gb win 81");
    product1.setRam(16);
    product1.setCpu(4);
    product1.setDiskType("ssd");
    product1.setDiskSpace(500);
    product1.setGpu("Nvidia GeForce GTX 970M 3 GB GDDR5");
    productDao.insertProductInDB(product1, 3);

    Smartphone product2 = Smartphone();
    product2.setPrice(1400);
    product2.setModel("iPhone");
    product2.setManufacturer("Apple");
    product2.setDescription("This is an Apple iPhone");
    product2.setBatteryLife(23);
    product2.setCanRecord4k(true);
    product2.setScreenSize(5.5);
    product2.setPhotoUrl("test");
    productDao.insertProductInDB(product2, 14);

    vector<Availability> products = productDao.fetchAllProductsFromDB();

    for (vector<Availability>::iterator iter = products.begin(); iter != products.end(); iter++) {
        ProductBase product = iter->getProduct();

        fprintf(stdout, "Product serial: %d\n", product.getSerial());
        fprintf(stdout, "Product description: %s\n", product.getDescription());
        w.setLabel(product.getDescription());
//        fprintf(stdout, "Product model: %s\n", product.getModel());
//        fprintf(stdout, "Product manufacturer: %s\n", product.getManufacturer());
//        fprintf(stdout, "Product price: %f\n", product.getPrice());
    }

    return a.exec();
}
