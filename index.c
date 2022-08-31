#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


struct Register {
    char book[60];
    char author[30];
    char year[5];
};

//Functions////////////////////////////////////

void addbook();
void readbook();
void writeData(struct Register newRegister);
void menu();
void br();

//////////////////////////////////////////////

int main () {

    system("cls");
    //system("clear") - for linux
    //system("cls") - for windows
    menu();
}

void br() {
    printf("-------------------------------------------------\n");
}

void addbook() {

    system("cls");

    br();
    printf("------------------Book Register------------------\n");
    br();
    
    printf("\n");

    struct Register newRegister;

    fflush(stdin); // Clear Buffer
    printf("Enter the book name: ");
    fgets(newRegister.book, sizeof(newRegister.book), stdin); // Get Input

    fflush(stdin);
    printf("Enter the author name: ");
    fgets(newRegister.author, sizeof(newRegister.author), stdin);

    fflush(stdin);
    printf("Enter the year of publication: ");
    fgets(newRegister.year, sizeof(newRegister.year), stdin);

    char option;

    // Do-While for Check Info

    do {
        system("cls");
        fflush(stdin);
        printf("----------------------------------\n");
        printf("Check Info:\n");
        printf("----------------------------------\n");
        printf("Book: %s", newRegister.book);
        printf("Author: %s", newRegister.author);
        printf("Year: %s", newRegister.year);   
        printf("\n----------------------------------\n"); 
        printf("\nDo you want to continue with this information? (y/n)\n");
        
        scanf("%c", &option);

    } while (option != 'y' && option != 'n');

    if (option == 'y') {
        writeData(newRegister);
    } else {
        menu();
    }
}

void writeData(struct Register newRegister) {

    char line1[] = "--------------------------------\n";
    char line2[] = "\n--------------------------------\n\n";

    char book[] = "Book: ";
    char author[] = "Author: ";
    char year[] = "Year: ";
    
    char cat[250]; // String concatenated

    strcat(cat, book);
    strcat(cat, newRegister.book);
    strcat(cat, author);
    strcat(cat, newRegister.author);
    strcat(cat, year);
    strcat(cat, newRegister.year);

    FILE *database; // Database pointer

    database = fopen("database.txt", "a+"); // Open database

    if (database == NULL) {
        printf("Error opening file\n");
    } // Error Message
    
    // Write in the database
    fputs(line1, database);
    fputs(cat, database);
    fputs(line2, database);
    
    //Close database
    fclose(database);

    char option;
    
    //Do-While for back to menu or register a new book

    do {
        system("cls");
        fflush(stdin);
        printf("\nRegistered Data!\n");
        printf("(1) Menu\n(2) Register a new book\n");
        scanf("%c", &option);

    } while (option != '1' && option != '2');

    if (option == '1') {
        menu();
    } else {
        addbook();
    }
}

void readbook() {
    system("cls");
    
    struct Register Register; // get database datas

    FILE *database; // database pointer

    database = fopen("database.txt", "r"); // Open on the read mode

    if (database == NULL) {
        printf("Error opening file");
    } //error message

    char text_str[50]; // get one string from the database

    while(fgets(text_str, 20, database) != NULL) {
        printf("%s", text_str);
    }; // get all strings from the database with a loop and print in terminal

    int option = 0;

    // Do-While for back menu

    do {
        printf("Enter (1) for back menu\n");
        scanf("%d", &option);
        if (option != 1) {
            printf("Invalid command");
        }
    } while (option != 1);

    if (option == 1) {
        menu();
    }
}

void menu () {

    char option;

    do {
        system("cls");
        br();
        printf("------------------Books Register-----------------\n");
        br();

        printf("\n");
        printf("Choose a option:\n");
        printf("(1) Register book\n(2) List books\n(3) Exit\n");
        scanf("%c", &option);
    } while (option != '1' && option != '2' && option != '3' && option != '4');

    switch (option) {
        case '1':
            addbook();
            break;
        case '2':
            readbook();
            break;
        case '3':
            system("pause");
        
    }
}