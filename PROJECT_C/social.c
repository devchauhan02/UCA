#include <stdio.h>
// Main function to test the social network
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