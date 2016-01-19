#include "cart.h"
#include "ProductBase.h"


void Cart::setCart(map<ProductBase,int> customerCart){
    this->getInstance().cart=customerCart;
}


map<ProductBase,int> Cart::getCart(){
    return this->cart;
}
