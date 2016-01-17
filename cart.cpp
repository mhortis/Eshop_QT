#include "cart.h"
#include "ProductBase.h"


void Cart::addProductToCart(ProductBase product,int quantity){
    this->cart[product.getSerial()]=quantity;
}

map<int,int> Cart::getCart(){
    return this->cart;
}
