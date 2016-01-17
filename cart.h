#ifndef CART_H
#define CART_H
#include "ProductBase.h"

class Cart
{
public:
    static Cart& getInstance(){
        static Cart instance;
        return instance;
    }

    void addProductToCart(ProductBase product,int quantity);
    map<int,int> getCart();
private:
    map<int,int> cart;
};

#endif // CART_H
