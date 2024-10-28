#include<stdio.h>

struct productDetails{
    char name[50];
    int productID;
    float price;
    int availableQunatity;

};

struct sale{
    int productID;
    int quantitySold;
    float totalPrice;

};

struct inventory{
    struct productDetails inven;
    int totalNoOfProduct;
};

struct salesRecord{
    struct sale record[50];
    int totaSales;
};

int main(){

}