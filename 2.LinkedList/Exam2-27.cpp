// Given a linked list, check if it is a palindrome or not. 
//For example,{ 1, 3, 5, 3, 1}

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next;
};

struct lisT {
    Node* initialNode, * lastedNode;
};

//khoi tao danh sach da thuc
void newList(lisT *l) {
    l->initialNode = l->lastedNode = NULL;
}

//tao mot node moi
Node* callNode(int N) {
    Node* p;
    p = new Node;
    if (p == NULL) return NULL;
    p->value = N;
    p->next = NULL;
    return p;
}

//Gan Node p vao danh sach
void addNode(lisT* list, Node*p) {
    if (list->initialNode == NULL) { list->initialNode = list->lastedNode = p;}
    else
    {
        list->lastedNode->next = p; //gan dia chi nut cuoi bang p
        list->lastedNode = p; //chuyen p thanh nut cuoi
    }
}

//them node voi he so va so mu cho truoc
void attachNode(lisT*list, int N) {
    Node* pDT = callNode(N);
    if (pDT == NULL) return;
    addNode(list, pDT);
}

//tao da thuc
void createList(lisT *list) {
    int number;
    cout << "Number of elements of the array: "; cin >> number;
    int N;
    int i = 0; //dem so phan tu
    do
    {
    i++;
    cout << "Enter the element number " << i << endl;
    cout << "Enter value: "; cin >> N;
    attachNode(list, N);
    cout << endl;
    } while (i != number);
}

void printList(lisT list) {
    Node* p;
    p = list.initialNode;
    cout << "\nList number:";
    while (p != NULL) {
    cout << p->value <<"   ";
    p = p->next;
    }
}

Node* attact(Node* d, int M){
    Node *p;
    p->value = M;
    d->next = p;
    d = p;
    return d;
}

int checkPalindrome(struct Node** left, struct Node* right)
{
    if (right == NULL) {return 1;}
    int result = checkPalindrome(left, right->next) && ((*left)->value == right->value);
    (*left) = (*left)->next;
    return result;
}
 
int checkPalin(struct Node* head) {
    return checkPalindrome(&head, head);
}

int main()
{
    lisT List1;
    newList(&List1);
    createList(&List1);
    if (checkPalin(List1.initialNode)) {
        cout << "The linked list is a palindrome";
    }
    else {
        cout << "The linked list is not a palindrome";
    }
}

