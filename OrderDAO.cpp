#include "OrderDAO.h"

OrderDAO::OrderDAO(QSqlDatabase database)
{
    this->db = database;
}

Order OrderDAO::insertOrderInDB(Customer cust, map<ProductBase, int> cart) {
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        Order order;
        return order;
    }

    QSqlQuery query(db);

    query.prepare("insert into orders (STATUS, COST)"
        "values('Processing', ?);");

    double totalCost = 0;
    for (map<ProductBase, int>::iterator mapIter = cart.begin(); mapIter != cart.end(); mapIter++) {
        ProductBase cur = mapIter->first;
        int quantity = mapIter->second;
        totalCost += quantity * cur.getPrice();
    }

    query.addBindValue(totalCost);

    if(query.exec()){
        int orderID = query.lastInsertId().toInt();
        for (map<ProductBase, int>::iterator mapIter = cart.begin(); mapIter != cart.end(); mapIter++) {
            query.prepare("insert into order_items (ORDER_ID, ITEM_ID, QUANTITY)"
                          "values(?,?,?);");
            ProductBase cur = mapIter->first;
            int quantity = mapIter->second;
            query.addBindValue(orderID);
            query.addBindValue(cur.getSerial());
            query.addBindValue(quantity);

            if(!query.exec()){
                qDebug() << "Error in insertion of Order Item. Error code: " << query.lastError() << endl;
                Order order;
                return order;
            }
        }
        Order order;
        order.setOrderBuyer(cust);
        order.setOrderCost(totalCost);
        order.setOrderItems(cart);
        order.setOrderNumber(orderID);
        order.setOrderStatus("Processing");
        return order;
    }
    else{
        qDebug() << "Error in insertion of new Order. Error code: " << query.lastError() << endl;
        Order order;
        return order;
    }
}

Order OrderDAO::fetchOrderByIDFromDB(int orderID){
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        Order order;
        return order;
    }

    QSqlQuery orderQuery(db);

    orderQuery.prepare("select * from orders where ID = ?");
    orderQuery.addBindValue(orderID);

    if(orderQuery.exec()){
        if(orderQuery.next()){
            Order order;
            order.setOrderNumber(orderID);
            order.setOrderStatus(orderQuery.value(orderQuery.record().indexOf("STATUS")).toString().toLocal8Bit().constData());
            order.setOrderCost(orderQuery.value(orderQuery.record().indexOf("COST")).toDouble());
            int customerID = orderQuery.value(orderQuery.record().indexOf("CUSTOMER_ID")).toInt();

            QSqlQuery userQuery(db);
            userQuery.prepare("select * from users where ID = ?");
            userQuery.addBindValue(customerID);

            if(userQuery.exec()){
                if(userQuery.next()){
                    Customer customer;
                    customer.setAddress(userQuery.value(userQuery.record().indexOf("ADDRESS")).toString().toLocal8Bit().constData());
                    customer.setAfm(userQuery.value(userQuery.record().indexOf("AFM")).toString().toLocal8Bit().constData());
                    customer.setPassword(userQuery.value(userQuery.record().indexOf("PASSWORD")).toString().toLocal8Bit().constData());
                    customer.setPhoneNumber(userQuery.value(userQuery.record().indexOf("PHONE")).toString().toLocal8Bit().constData());
                    customer.setType(userQuery.value(userQuery.record().indexOf("TYPE")).toInt());
                    customer.setUserID(customerID);
                    customer.setUsername(userQuery.value(userQuery.record().indexOf("USERNAME")).toString().toLocal8Bit().constData());
                    order.setOrderBuyer(customer);

                    QSqlQuery orderItemQuery(db);
                    orderItemQuery.prepare("select * from order_items where ORDER_ID = ?");
                    orderItemQuery.addBindValue(orderID);

                    if(orderItemQuery.exec()){
                        map<ProductBase, int> products;
                        while(orderItemQuery.next()){
                            int quantity = orderItemQuery.value(orderItemQuery.record().indexOf("QUANTITY")).toInt();
                            int productSerial = orderItemQuery.value(orderItemQuery.record().indexOf("ITEM_ID")).toInt();

                            QSqlQuery productQuery(db);
                            productQuery.prepare("select * from products where SERIAL = ?");
                            productQuery.addBindValue(productSerial);
                            if(productQuery.exec()){
                                if(productQuery.next()){
                                    ProductBase product;
                                    product.setDescription(productQuery.value(productQuery.record().indexOf("DESCRIPTION")).toString().toLocal8Bit().constData());
                                    product.setManufacturer(productQuery.value(productQuery.record().indexOf("MANUFACTURER")).toString().toLocal8Bit().constData());
                                    product.setModel(productQuery.value(productQuery.record().indexOf("MODEL")).toString().toLocal8Bit().constData());
                                    product.setPhotoUrl(productQuery.value(productQuery.record().indexOf("PHOTOURL")).toString().toLocal8Bit().constData());
                                    product.setPrice(productQuery.value(productQuery.record().indexOf("PRICE")).toDouble());
                                    product.setSerial(productQuery.value(productQuery.record().indexOf("SERIAL")).toInt());
                                    product.setType(productQuery.value(productQuery.record().indexOf("TYPE")).toInt());
                                    products.insert({product, quantity});
                                }
                            }
                        }
                        order.setOrderItems(products);
                        return order;
                    }
                }
            }
        }
        else{
            qDebug() << "Error in fetching Order. Error code: " << orderQuery.lastError() << endl;
            Order order;
            return order;
        }
    }
    else{
        qDebug() << "Error in fetching Order. Error code: " << orderQuery.lastError() << endl;
        Order order;
        return order;
    }
}

int OrderDAO::updateOrderStatusInDB(int orderID, string newOrderStatus){
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        return false;
    }

    QSqlQuery query(db);

    query.prepare("update orders set STATUS = ? WHERE ID = ?");
    query.addBindValue(QString::fromStdString(newOrderStatus));
    query.addBindValue(orderID);

    if(query.exec()){
        return true;
    }
    else{
        qDebug() << "Error in update of Order. Error code: " << query.lastError() << endl;
        return false;
    }
}

int OrderDAO::removeOrderFromDB(int orderID){
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        return false;
    }

    QSqlQuery query(db);

    query.prepare("delete from orders WHERE ID = ?");
    query.addBindValue(orderID);

    if(query.exec()){
        return true;
    }
    else{
        qDebug() << "Error in removal of Order. Error code: " << query.lastError() << endl;
        return false;
    }
}
