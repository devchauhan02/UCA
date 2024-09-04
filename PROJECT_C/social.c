#include <stdio.h>
#include<stdlib.h>
// Main function to test the social network

#define INITIAL_CAPACITY 10

// Define a simple vector structure
typedef struct {
    void **items;
    int capacity;
    int current_cap;
} Vector;

Vector* vector_create() {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->capacity = INITIAL_CAPACITY;
    v->current_cap = 0;
    v->items = (void **)malloc(sizeof(void *) * v->capacity);
    return v;
}

void vector_resize(Vector *v, int capacity) {
    void **items = (void **)realloc(v->items, sizeof(void *) * capacity);
    if (items) {
        v->items = items;
        v->capacity = capacity;
    }
}

void vector_push_back(Vector *v, void *item) {
    if (v->capacity == v->current_cap) {
        vector_resize(v, v->capacity * 2);
    }
    v->items[v->current_cap++] = item;
}

int vector_size(Vector *v) {
    return v->current_cap;
}

void* vector_get(Vector *v, int index) {
    if (index >= 0 && index < v->current_cap) {
        return v->items[index];
    }
    return NULL;
}

int vector_contains(Vector *v, void *item) {
    for (int i = 0; i < v->current_cap; i++) {
        if (v->items[i] == item) {
            return 1;
        }
    }
    return 0;
}

// Define User and Post structures
typedef struct {
    char *content;
    char *timestamp;
} Post;

typedef struct {
    char *username;
    char *password;
    Vector *followers;
    Vector *following;
    Vector *posts;
} User;

// Define the Social Network structure
typedef struct {
    User **users;
    int capacity;
    int size;
} SocialNetwork;


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