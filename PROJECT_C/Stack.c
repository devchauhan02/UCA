#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNodeStack(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("NULL\n");
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int StackisEmpty(struct Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
struct Node* Stackpush(struct Node* top, int data) {
    struct Node* newNode = createNodeStack(data);
    newNode->next = top;
    top = newNode;
    return top;
}

// Function to pop an element from the stack
struct Node* pop(struct Node* top, int* poppedData) {
    if (StackisEmpty(top)) {
        printf("Stack Underflow!\n");
        return top;
    }
    *poppedData = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

// Function to peek the top element of the stack
int Stackpeek(struct Node* top) {
    if (!StackisEmpty(top)) {
        return top->data;
    }
    printf("Stack is empty!\n");
    return -1; // Returning -1 when the stack is empty
}

// Function to display the stack elements
void Stackdisplay(struct Node* top) {
    if (StackisEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver code to test the stack operations
int main() {
    struct Node* top = NULL; // Initialize the stack

    top = Stackpush(top, 10);
    top = Stackpush(top, 20);
    top = Stackpush(top, 30);

    Stackdisplay(top);

    int poppedData;
    top = pop(top, &poppedData);
    printf("Popped element: %d\n", poppedData);

    Stackdisplay(top);

    printf("Top element: %d\n", Stackpeek(top));

    return 0;
}
