// Given a linked list, reverse every adjacent group of nodes where is a given positive integer k.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
 
    *head = newNode;
}
struct Node* reverseK(struct Node** current, int k)
{
    struct Node* prev = NULL;
    int count = 0;
    while (*current && count++ < k)
    {
        struct Node* next = (*current)->next;
        (*current)->next = prev;
        prev = *current;
        *current = next;
    }
    return prev;
}
struct Node *reverseInGroups(struct Node *head, int k)
{
    if (head == NULL) {
        return NULL;
    }
    struct Node* current = head;
    struct Node* prev = reverseK(&current, k);
    head->next = reverseInGroups(current, k);
    return prev;
}
 
int main(void)
{
    int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n = sizeof(keys)/sizeof(keys[0]);
    struct Node* head = NULL;
    for (int i = n - 1; i >=0; i--) {
        push(&head, keys[i]);
    }
    head = reverseInGroups(head, 3);
    printList(head);
    return 0;
}
