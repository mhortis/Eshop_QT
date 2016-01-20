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

    void setCart(map<ProductBase,int> customerCart);
    map<ProductBase,int> getCart();
private:
    map<ProductBase,int> cart;
};

#endif // CART_H
