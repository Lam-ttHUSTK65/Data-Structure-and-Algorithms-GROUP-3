/*
Given two linked lists, merge their nodes to make one list, taking nodes alternately between the two lists. 
If either list runs out, all the nodes should be taken from the other list.

For example, merging lists {1, 2, 3} and {7, 13, 1} should yield {1, 7, 2, 13, 3, 1}.
*/

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

lisT mergeList(lisT &list1 , lisT &list2){
	lisT list3 ;
    newList(&list3) ;
	Node* p1 = list1.initialNode ;
	Node* p2 = list2.initialNode ;
	Node* p3 = list3.initialNode ;
	while(p1 != NULL||p2 != NULL){
			p3->next = p1 ;
			p3=p1 ;
			p1=p1->next ;
	}
	if(p1==NULL){
		p3->next=p2;
	}
	else{
		p3->next=p1 ;
	} 
	return list3 ;
}

int main()
{
    lisT List1;
    newList(&List1);
    createList(&List1);

    lisT List2;
    newList(&List2);
    createList(&List2);

    lisT List3 = mergeList(List1, List2);
    printList(List3);
}