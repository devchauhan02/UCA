#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

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

SocialNetwork* createNetwork() {
    SocialNetwork *network = (SocialNetwork *)malloc(sizeof(SocialNetwork));
    network->capacity = INITIAL_CAPACITY;
    network->size = 0;
    network->users = (User **)malloc(sizeof(User *) * network->capacity);
    return network;
}

void network_resize(SocialNetwork *network, int capacity) {
    User **users = (User **)realloc(network->users, sizeof(User *) * capacity);
    if (users) {
        network->users = users;
        network->capacity = capacity;
    }
}

void network_add_user(SocialNetwork *network, User *user) {
    if (network->size == network->capacity) {
        network_resize(network, network->capacity * 2);
    }
    network->users[network->size++] = user;
}

User* network_get_user(SocialNetwork *network, const char *username) {
    for (int i = 0; i < network->size; i++) {
        if (strcmp(network->users[i]->username, username) == 0) {
            return network->users[i];
        }
    }
    return NULL;
}

// Function to get the current time as a string
char* getCurrentTime() {
    time_t rawtime;
    struct tm *timeinfo;
    char *buffer = (char *)malloc(20);  // Allocating 20 bytes for HH:MM:SS format

    time(&rawtime);  // Get the current time
    timeinfo = localtime(&rawtime);  // Convert it to local time representation

    // Format the time as HH:MM:SS
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", timeinfo);  // 24-hour format
    return buffer;
}

// Function to save users to a file
void saveUsers(SocialNetwork *network) {
    FILE *file = fopen("users.txt", "w");
    if (file) {
        for (int i = 0; i < network->size; i++) {
            User *user = network->users[i];
            fprintf(file, "%s %s\n", user->username, user->password);
            for (int j = 0; j < vector_size(user->posts); j++) {
                Post *post = (Post *)vector_get(user->posts, j);
                fprintf(file, "POST %s %s\n", post->timestamp, post->content);
            }
            fprintf(file, "END\n");
        }
        fclose(file);
    } else {
        perror("Error opening file to save users");
    }
}

// Function to load users from a file
void loadUsers(SocialNetwork *network) {
    FILE *file = fopen("users.txt", "r");
    if (file) {
        char username[50], password[50], content[100], timestamp[20];
        while (fscanf(file, "%s %s", username, password) != EOF) {
            User *newUser = (User *)malloc(sizeof(User));
            newUser->username = strdup(username);
            newUser->password = strdup(password);
            newUser->followers = vector_create();
            newUser->following = vector_create();
            newUser->posts = vector_create();
            while (fscanf(file, "%s", timestamp) != EOF && strcmp(timestamp, "END") != 0) {
                if (strcmp(timestamp, "POST") == 0) {
                    // Read the timestamp
                    fscanf(file, "%s", timestamp);
                    // Read the content, which might be on a new line
                    if (fgets(content, sizeof(content), file) != NULL) {
                        // Remove the newline character from the content
                        content[strcspn(content, "\n")] = 0;
                        Post *newPost = (Post *)malloc(sizeof(Post));
                        newPost->content = strdup(content);
                        newPost->timestamp = strdup(timestamp);
                        vector_push_back(newUser->posts, newPost);
                    }
                }
            }
            network_add_user(network, newUser);
        }
        fclose(file);
    } else {
        perror("Error opening file to load users");
    }
}

void registerUser(SocialNetwork *network, const char *username, const char *password) {
    if (network_get_user(network, username) != NULL) {
        printf("Username already exists.\n");
        return;
    }

    User *newUser = (User *)malloc(sizeof(User));
    newUser->username = strdup(username);
    newUser->password = strdup(password);
    newUser->followers = vector_create();
    newUser->following = vector_create();
    newUser->posts = vector_create();

    network_add_user(network, newUser);
    printf("User %s registered successfully.\n", username);
}

User* loginUser(SocialNetwork *network, const char *username, const char *password) {
    User *user = network_get_user(network, username);
    if (user && strcmp(user->password, password) == 0) {
        printf("User %s logged in successfully.\n", username);
        return user;
    }
    printf("Invalid username or password.\n");
    return NULL;
}

// Main function to test the social network
int main() {
    SocialNetwork *network = createNetwork();
    loadUsers(network);  // Load users from file

    int choice;
    char username[50], password[50], content[100];

    while (1) {
        printf("\n1. Register\n2. Login\n3. View All Users\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            registerUser(network, username, password);
        } else if (choice == 2) {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            User *loggedInUser = loginUser(network, username, password);
        } 
    }
    return 0;
}