#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

/* Insert at beginning */
void insertAtBeginning(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

/* Insert at end */
void insertAtEnd(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Insert at a given position (1-based index) */
void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is greater than the length of the list\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

/* Delete from beginning */
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

/* Delete from end */
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

/* Delete by value */
void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head->data == value) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

/* Search for a value */
void search(int value) {
    struct Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Found at position %d\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Not found\n");
}

/* Count nodes */
int count() {
    struct Node* temp = head;
    int cnt = 0;

    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

/* Reverse the list */
void reverse() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

/* Print the list */
void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main function */
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAtPosition(15, 3);

    printList();

    deleteFromBeginning();
    deleteFromEnd();
    deleteByValue(15);

    printList();

    search(20);
    printf("Total nodes: %d\n", count());

    reverse();
    printList();

    return 0;
}
