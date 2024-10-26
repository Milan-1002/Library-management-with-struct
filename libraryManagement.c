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
    int stdID;
    char bookTitle[50];
};

void addBook(struct book b1[], int *bookCount);
// it receives the b1 array from the main
// add a title, author name and increase the bookcount

void addStudent(struct student std[], int  *studentCount);
//it receives the std array and the student  count from the main
// add a name and id and increase the student count

void  borrowBook(struct book b1[], int bookCount,  struct student std[], int studentCount, struct borrowRecord borrow[], int *recordCount);
// it takes the book title from the user
// checks if the book is available using the for loop till bookcount
// if available, marks the book as borrowed
// add the student id and book title to the borrow record
// increment the  record count
// display the message

void displayBook(struct book b1[], int bookCount);
// it takes the book array and book count from the main
// displays the book title and author name
// displays the book status (available or borrowed)


void displayBorrowRecord(struct borrowRecord borrow[], int recordCount);
//  it takes the borrow record array and record count from the main
// displays the student id and book title 




int main(){
    struct book b1[100];
    struct student std[100];
    struct borrowRecord borrow[100];

    int bookCount = 0, studentCount = 0, recordCount = 0;
    int choice;

do{
    printf("\nLIBRARY MANAGEMENT SYSTEM\n");
    printf("-------------------------\n");
    printf("Please Enter the choice\n");
    printf("1.Add a book\n");
    printf("2.Add a student\n");
    printf("3.Borrow book\n");
    printf("4.Display book\n");
    printf("5.Display Borrowed book\n");
    printf("6.Exit\n");
    printf("please Enter a choice\n");
    scanf("%d",&choice);

    switch(choice){
        
            case 1:
            addBook(b1, &bookCount);
            break;

            case 2:
            addStudent(std, &studentCount);
            break;

            case 3:
            borrowBook(b1, bookCount, std, studentCount, borrow, &recordCount);
            break;

            case 4:
            displayBook(b1, bookCount);
            break;

            case 5:
            displayBorrowRecord(borrow,  recordCount);
            break;

            case 6:
            printf("Exiting....\n");
            break;

            default:
            printf("Invalid choice please enter the choice again\n");
            continue;


        }
    }while(choice != 6);
    return 0;
}

void addBook(struct book b1[], int *bookCount){
    printf("Enter book title\n");
    scanf(" %[^\n]", b1[*bookCount].bookTitle);  // Read book title
    printf("Enter book author name\n");
    scanf(" %[^\n]",b1[*bookCount].author);
    b1[*bookCount].isBorrowed = 0;              // mark book as available
    (*bookCount)++;                             // increment book count
    printf("Book added succesfully\n");
    
}

void addStudent(struct student std[], int  *studentCount){
    printf("Enter student name\n");
    scanf(" %[^\n]", std[*studentCount].stdName);
    printf("Enter the student ID\n");
    scanf("%d", &std[*studentCount].stdID);
    (*studentCount)++;
    printf("Student Added successfully\n");
}

void  borrowBook(struct book b1[], int bookCount,  struct student std[], int studentCount, struct borrowRecord borrow[], int *recordCount){
    int i, studentId;
    char bookTitle[100];
    printf("Enter the book title  to borrow\n");
    scanf(" %[^\n]",bookTitle);
   

    // check if the entered book exist
    for(i = 0; i< bookCount; i++){
        if(strcmp(b1[i].bookTitle,bookTitle)==0){
            if(b1[i].isBorrowed == 0){
                b1[i].isBorrowed = 1;  // marks the book as borrowed
                
                // update in the borrow record
                printf("Enter the student  ID\n");
                scanf("%d", &studentId);
                borrow[*recordCount].stdID = studentId;
                strcpy(borrow[*recordCount].bookTitle, bookTitle);
                (*recordCount)++;
                printf("Book borrowed successfully\n");
                return;

            }
            else{
                printf("Book is already borrowed\n");
                return;
            }
        }
    }
    printf("Sorry the book does not found\n");

}

void displayBook(struct book b1[], int bookCount){
    printf("available books list:\n");
    for(int i = 0; i<bookCount; i++){
        printf("Title: %s, Author: %s, status: %s\n",b1[i].bookTitle, b1[i].author,b1[i].isBorrowed ? "Borrowed": "Available");
    }

}

void displayBorrowRecord(struct borrowRecord borrow[], int recordCount){
    printf("Borrow record list:\n");
    for(int i = 0; i< recordCount; i++){
        printf("Student ID: %d, Book Title: %s\n", borrow[i].stdID, borrow[i].bookTitle);

}
}




