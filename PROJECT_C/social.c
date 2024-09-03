#include <stdio.h>
#include<stdlib.h>
// Main function to test the social network

#define INITIAL_CAPACITY 10

// Define a simple vector structure
typedef struct {
    void **items;
    int capacity;
    int total;
} Vector;


int main() {
    int choice;
    char username[50], password[50], content[100];

    while (1) {
        printf("\n1. Register\n2. Login\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            
        } else if (choice == 2) {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
          
        }
    }
    return 0;
}