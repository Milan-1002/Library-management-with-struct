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
    struct inventory in[50];
    struct salesRecord sR[50];

    int totalQuantity = 0;
    int totalSalesAmount = 0;
    int salesRecordCount = 0;
    printf("\nInventory Management System\n");
    printf("1.Add a product\n");
    printf("2.Record a sale\n");
    printf("3.Display Inventory\n");
    printf("4.Display sales record\n");
    printf("5.Exit\n");

    int choice;
    printf("Enter a choice\n");
    scanf("%d",&choice);

    switch(choice){
        do
        {
            case 1:
            addProduct(in, &totalQuantity);
            break;

            case 2:
            recordSale(sR,&totalSalesAmount,&salesRecordCount);
            break;

            case 3:
            displayInventory(in, totalQuantity);
            break;

            case 4:
            displaySalesRecord(sR,salesRecordCount);
            break;

            case 5:
            printf("Exiting...\n");

            default:
            printf("\nPlease Enter a valid choice\n");
            continue;


            
        } while (choice != 5);
        
    }



}