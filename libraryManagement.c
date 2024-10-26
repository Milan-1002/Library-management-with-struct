#include<stdio.h>
#include<string.h>

struct student{
    char stdName[50];
    int stdID;
};

struct book{
    char bookTitle[100];
    char author[100];
    int isBorrowed; // 0 = available 1 = borrowed


};
struct borrowRecord{
    char stdName[50];
    int stdID;
    char bookTitle[50];
};

void addBook(struct book *b1, int *bookCount);
// it receives the b1 array from the main
// add a title, author name and increase the bookcount

int main(){
    struct book b1[100];
    struct student std[100];
    struct borrowRecord borrow;

    int bookCount = 0; 
    int choice;

    printf("LIBRARY MANAGEMENT SYSTEM\n");
    printf("-------------------------\n");
    printf("Please Enter the choice\n");
    printf("1.Add a book\n");
    printf("2.Add a student\n");
    printf("3.Borrow book\n");
    printf("4.Display book\n");
    printf("5.Display student\n");
    printf("6.Display borrow record\n");
    printf("7.Exit\n\n");
    printf("please Enter a choice\n");
    scanf("%d",&choice);

    switch(choice){
        do{
            case 1:
            addBook(&b1, &bookCount);
            break;

            case 2:
            addStudent(&std);
            break;

            case 3:
            borrowBook(&b1,&std);
            break;

            case 4:
            displayBook(b1);
            break;

            case 5:
            displayBorrowRecord(borrow);
            break;

            case 6:
            printf("Exiting....\n");


        }while(choice != 7);
    }
    

}

void addBook(struct book *b1, int *bookCount){
    
}


