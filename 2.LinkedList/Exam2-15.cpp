/*
Given two linked lists, merge their nodes to make one list, taking nodes alternately between the two lists. 
If either list runs out, all the nodes should be taken from the other list.

For example, merging lists {1, 2, 3} and {7, 13, 1} should yield {1, 7, 2, 13, 3, 1}.
*/

#include <bits/stdc++.h>
using namespace std;

// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        cout << ptr->data << "  ";
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
 
// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
// Function to construct a linked list by merging alternate nodes of
// two given linked lists using a dummy node
struct Node* shuffleMerge(struct Node* a, struct Node* b)
{
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;
 
    while (1)
    {
        // empty list cases
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
 
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
 
        // common case: move two nodes to the tail
        else {
            tail->next = a;
            tail = a;
            a = a->next;
 
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
 
    return dummy.next;
}
 
 
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node *a = NULL, *b = NULL;
    for (int i = n - 1; i >= 0; i = i - 2) {
        push(&a, keys[i]);
    }
 
    for (int i = n - 2; i >= 0; i = i - 2) {
        push(&b, keys[i]);
    }
 
    // print both lists
    cout << "First List: ";
    printList(a);
 
    cout << "Second List: ";
    printList(b);
 
    struct Node* head = shuffleMerge(a, b);
    cout << "After Merge: ";
    printList(head);

    return 0;
}
