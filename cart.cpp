#include "cart.h"
#include "ProductBase.h"


void Cart::setCart(map<ProductBase,int> customerCart){
    this->cart=customerCart;
}

void Cart::clearCart(){
    this->cart.clear();
}

map<ProductBase,int> Cart::getCart(){
    return this->cart;
}
