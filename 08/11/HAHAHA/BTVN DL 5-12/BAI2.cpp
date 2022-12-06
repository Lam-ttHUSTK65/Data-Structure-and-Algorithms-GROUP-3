// Trường hợp với M = 1. 
// Tương tự với trường hợp M = 2 (node chỉ đến next thêm 1 lần)
// Tương tự với trường hợp M = 3 (node chỉ đến next thêm 2 lần)

#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int counter = 1;

struct node
{
    int number;
    node *next;
};

node *start = NULL, *temp = NULL;

node *create(int num)
{
    node *newnode = new node;
    newnode -> number = num;
    newnode -> next = NULL;
    return newnode;
}

void insertNode(int value)
{
    if(start == NULL)
    {
        start = temp = create(value);
    }
    else
    {
        temp -> next = create(value);
        temp = temp -> next;
    }

}

int main()
{
    node *delptr = NULL;
    int num = 1;
    cout<<"ENTER NUMBER : ";
    cin>>num;
    while(counter<num + 1)
    {
        insertNode(counter);
        counter++;
    }
    temp -> next = start;
    temp = start;
    while(true)
    {
        if(temp -> next -> number == temp -> number)
        {
            cout<<"REQUIRED POSITION : "<<temp -> number;
            break;
        }
        delptr = temp -> next;
        temp -> next = delptr -> next;
        delete delptr;
        temp = temp -> next;
    }
    return 0;
}

