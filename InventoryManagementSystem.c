#include <stdio.h>

struct productDetails {
    char name[50];
    int productID;
    float price;
    int availableQuantity;  // Fixed typo
};

struct sale {
    int productID;
    int quantitySold;
    float totalPrice;
};

struct inventory {
    struct productDetails inven;
    int totalNoOfProduct;
};

struct salesRecord {
    struct sale record[50];
    int totalSales;
};

void addProduct(struct inventory in[], int *totalQuantity);
// prompt the user to  enter the product details
// add the product to the inventory
// diplay the product was added succesfully

void recordSale(struct salesRecord sR[], struct inventory in[], int *totalQuantity, float *totalSalesAmount, int *salesRecordCount);
// Get the product ID and quantity sold from the user.
// Check if the product exists and if the available quantity is sufficient.
// Update the product’s available quantity in the Inventory.
// Calculate the total price for the sale.
// Add the sale record to the Sales Record structure.
// Increment the total sales count.

displayInventory(struct inventory in[], int *totalQuantity);
// Iterate through the Inventory structure’s product array.
// Display each product’s name, ID, price, and available quantity.

displaySalesRecord(struct salesRecord sR[], int *salesRecordCount);
// Iterate through the Sales Record structure’s sales array.
// Display each sale’s product ID, quantity sold, and total price.




int main() {
    struct inventory in[50];
    struct salesRecord sR[50];

    int totalQuantity = 0;
    float totalSalesAmount = 0;
    int salesRecordCount = 0;
    int choice;

    do {
        printf("\nInventory Management System\n");
        printf("1. Add a product\n");
        printf("2. Record a sale\n");
        printf("3. Display Inventory\n");
        printf("4. Display sales record\n");
        printf("5. Exit\n");

        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(in, &totalQuantity);
                break;

            case 2:
                recordSale(sR, in, &totalQuantity, &totalSalesAmount, &salesRecordCount);
                break;

            case 3:
                 displayInventory(in, &totalQuantity);
                break;

            case 4:
                 displaySalesRecord(sR, &salesRecordCount);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Please enter a valid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addProduct(struct inventory in[], int *totalQuantity) {
    printf("Enter the name of the product: ");
    scanf(" %[^\n]", in[*totalQuantity].inven.name);
    printf("Enter the product ID: ");
    scanf("%d", &in[*totalQuantity].inven.productID);
    printf("Enter the price of the product: ");
    scanf("%f", &in[*totalQuantity].inven.price);
    printf("Enter the total quantity of the product: ");
    scanf("%d", &in[*totalQuantity].inven.availableQuantity);
    (*totalQuantity)++;
    printf("Product added successfully.\n");
}

void recordSale(struct salesRecord sR[], struct inventory in[], int *totalQuantity, float *totalSalesAmount, int *salesRecordCount) {
    int productID, requiredQuantity;
    int productFound = 0;
    float totalPrice = 0;

    printf("Enter the product ID of the product sold: ");
    scanf("%d", &productID);
   

    for (int i = 0; i < *totalQuantity; i++) {
        if (productID == in[i].inven.productID) {
            productFound = 1;
            printf("Enter the required quantity of the product: ");
            scanf("%d", &requiredQuantity);
            if (in[i].inven.availableQuantity >= requiredQuantity) {
                in[i].inven.availableQuantity -= requiredQuantity;
                totalPrice = requiredQuantity * in[i].inven.price;
                *totalSalesAmount += totalPrice;

                sR[*salesRecordCount].record->productID = productID;
                sR[*salesRecordCount].record->quantitySold = requiredQuantity;
                sR[*salesRecordCount].record->totalPrice = totalPrice;

                (*salesRecordCount)++;
                printf("Sale recorded successfully.\n");
            } else {
                printf("Sorry, there is not enough stock.\n");
            }
            return;
        }
    }

    if (!productFound) {
        printf("The product ID %d is not available.\n", productID);
    }
}

displayInventory(struct inventory in[], int *totalQuantity){
    for (int i = 0; i < *totalQuantity; i++) {
        printf("Name:  %s\n", in[i].inven.name);
        printf("Product ID: %d\n", in[i].inven.productID);
        printf("Price:  $%.2f\n", in[i].inven.price);
        printf("Available Quantity:  %d\n", in[i].inven.availableQuantity);
    
}
}

displaySalesRecord(struct salesRecord sR[], int *salesRecordCount){
    for (int i = 0; i < *salesRecordCount; i++) {
        printf("The sales record up to now:\n");
        printf("-----------------------------\n");

        printf("Product ID:  %d\n", sR[i].record->productID);
        printf("Quantity Sold: %d\n",  sR[i].record->quantitySold);
        printf("Total Price: %.2f\n",  sR[i].record->totalPrice);

}
}
