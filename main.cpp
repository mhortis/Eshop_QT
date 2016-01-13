#include "mainwindow.h"
#include <QApplication>
#include "QtSql/QtSql"
#include "ProductDAO.h"
#include "UserDAO.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    QSqlDatabase m_db;

//    m_db = QSqlDatabase::addDatabase("QSQLITE");
//    QDir dir = QDir::currentPath();
//    QString dbPath =  dir.canonicalPath() + "/eshop.db";
//    m_db.setDatabaseName( dbPath);
//    if (!m_db.open())
//    {
//        qDebug() << dbPath;
//       qDebug() << "Error: connection with database fail";
//    }
//    else
//    {
//       qDebug() << dbPath;
//       qDebug() << "Database: connection ok";
//    }

//    ProductDAO productDao = ProductDAO(m_db);

////    PC product1 = PC();
////    product1.setPrice(599.99);
////    product1.setModel("gs60");
////    product1.setManufacturer("msi");
////    product1.setPhotoUrl("msi.jpg");
////    product1.setDescription("laptop msi gs60 2qe 226nl 4k edition 156 intel i7 4720hq 16gb 2x128gb 1tb gtx970m 3gb win 81");
////    product1.setRam(16);
////    product1.setCpu(4);
////    product1.setDiskType("ssd");
////    product1.setDiskSpace(500);
////    product1.setGpu("Nvidia GeForce GTX 970M 3 GB GDDR5");
////    productDao.insertProductInDB(product1, 3);

////    Smartphone product2 = Smartphone();
////    product2.setPrice(1400);
////    product2.setModel("iPhone");
////    product2.setManufacturer("Apple");
////    product2.setDescription("This is an Apple iPhone");
////    product2.setBatteryLife(23);
////    product2.setCanRecord4k(true);
////    product2.setScreenSize(5.5);
////    product2.setPhotoUrl("test");
////    productDao.insertProductInDB(product2, 14);

//    vector<Availability> products = productDao.fetchAllProductsFromDB();

//    for (vector<Availability>::iterator iter = products.begin(); iter != products.end(); iter++) {
//        ProductBase product = iter->getProduct();
//        cout << "Product serial: " << product.getSerial() << endl;
//        cout << "Product price: " << product.getPrice() << endl;
//        cout << "Product model: " << product.getModel() << endl;
//        cout << "Product manufacturer: " << product.getManufacturer() << endl;
//        cout << "Product description: " << product.getDescription() << endl;
//        if(product.getType() == 0){
//            PC pc = productDao.fetchPCDetailsFromDB(product.getSerial());
//            cout << "PC CPU: " << pc.getCpu() << endl;
//            cout << "PC disk type: " << pc.getDiskType() << endl;
//            cout << "PC disk space: " << pc.getDiskSpace() << endl;
//        }
//        else if(product.getType() == 1){
//            Smartphone smartphone = productDao.fetchSmartphoneDetailsFromDB(product.getSerial());
//            cout << "Smartphone screen size: " << smartphone.getScreenSize() << endl;
//            cout << "Smartphone battery life: " << smartphone.getBatteryLife() << endl;
//        }
//        else{
//            TV tv = productDao.fetchTVDetailsFromDB(product.getSerial());
//            cout << "TV screen size: " << tv.getScreenSize() << endl;
//            cout << "TV can show 3D: " << tv.getCanShow3d() << endl;
//        }
//        cout << "Availability: " << iter->getQuantity() << endl;

////                fprintf(stdout, "Product model: %s\n", product.getModel());
////        fprintf(stdout, "Product manufacturer: %s\n", product.getManufacturer());
////        fprintf(stdout, "Product price: %f\n", product.getPrice());
//    }

//    UserDAO userDao = UserDAO(m_db);

//    vector<UserBase> users = userDao.fetchUsersFromDB();

//    for (vector<UserBase>::iterator iter = users.begin(); iter != users.end(); iter++) {
//        if(iter->getType() == 1){
//            Person person = userDao.fetchPersonDetailsFromDB(iter->getUserID());
//            cout << "Person name: " << person.getName() << endl;
//            cout << "Person surname: " << person.getSurname() << endl;
//        }
//        else if(iter->getType() == 2){
//            Company company = userDao.fetchCompanyDetailsFromDB(iter->getUserID());
//            cout << "Company name: " << company.getCompanyName() << endl;
//            cout << "Company discount: " << company.getDiscount() << endl;
//        }
//        else{
//            cout << "Admin ID: " << iter->getUserID() << endl;
//            cout << "Admin username: " << iter->getUsername() << endl;
//            cout << "Admin password: " << iter->getPassword() << endl;
//        }
//    }

    return a.exec();
}
