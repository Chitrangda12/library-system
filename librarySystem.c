#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR_LEN 100
#define MAX_TITLE_LEN 100
struct Book {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
};
struct Book library[26][MAX_BOOKS];
int bookCount[26] = {0};
int hashFunction(char *author) {
    char firstLetter = author[0];
    if (firstLetter >= 'a' && firstLetter <= 'z') {
        firstLetter -= 32; 
    }
    return (firstLetter - 'A') % 26;
}
void addBook(int id, char *title, char *author) {
    int index = hashFunction(author);
    struct Book *book = &library[index][bookCount[index]];
    book->id = id;
    strcpy(book->title, title);
    strcpy(book->author, author);
    bookCount[index]++;
    printf("Book added: %s by %s\n", title, author);
}
void displayBooksSortedByAuthor() {
    printf("\nBooks in Library (Sorted by Author's Initial):\n");
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < bookCount[i]; j++) {
            struct Book *book = &library[i][j];
            printf("ID: %d, Title: %s, Author: %s\n", book->id, book->title, book->author);
        }
    }
}
int countTotalBooks() {
    int total = 0;
    for (int i = 0; i < 26; i++) {
        total += bookCount[i];
    }
    return total;
}
int main() {
    int choice, id, numBooks;
    char title[MAX_TITLE_LEN], author[MAX_AUTHOR_LEN];

    do {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book(s)\n");
        printf("2. Display All Books\n");
        printf("3. Count Total Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("How many books do you want to add? ");
                scanf("%d", &numBooks);
                getchar();
                for (int i = 0; i < numBooks; i++) {
                    printf("Enter Book ID: ");
                    scanf("%d", &id);
                    getchar();
                    printf("Enter Book Title: ");
                    fgets(title, MAX_TITLE_LEN, stdin);
                    title[strcspn(title, "\n")] = '\0'; 
                    printf("Enter Author Name: ");
                    fgets(author, MAX_AUTHOR_LEN, stdin);
                    author[strcspn(author, "\n")] = '\0'; 
                    addBook(id, title, author);
                }
                break;

            case 2:
                displayBooksSortedByAuthor();
                break;

            case 3:
                printf("Total number of books: %d\n", countTotalBooks());
                break;

            case 4:
                printf("Exiting Library Management System.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
