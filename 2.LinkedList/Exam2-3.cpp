#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to return new linked list node from the heap
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->next = NULL;
 
    return node;
}
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL");
}
 
// Function to add a new node at the tail end of the list instead of its head
struct Node* appendNode(struct Node** head, int key)
{
    struct Node* current = *head;
    struct Node* node = newNode(key);
 
    // special case for length 0
    if (current == NULL) {
        *head = node;
    }
    else {
        // locate the last node
        while (current->next != NULL) {
            current = current->next;
        }
 
        current->next = node;
    }
}
 
int main(void)
{
    // input keys
    int keys[] = {1, 2, 3, 4};
    int n = sizeof(keys)/sizeof(keys[0]);
 
    // points to the head node of the linked list
    struct Node* head = NULL;
 
    for (int i = 0; i < n; i++) {
        appendNode(&head, keys[i]);
    }
 
    // print linked list
    printList(head);
 
    return 0;
}
