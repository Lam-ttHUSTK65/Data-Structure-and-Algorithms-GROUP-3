#include <bits/stdc++.h>
using namespace std;

struct Ngay
{
    int ngay,thang,nam;
};
struct SinhVien
{
    char MaSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};
struct Node
{
	SinhVien data;
	Node* next;
};

struct LinkedList
{
	Node* start;
	Node* end;
};

Node* CreateNode(SinhVien init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;
	return node;
}

void CreateList(LinkedList& l){l.start = l.end = NULL;}

void Addstart(LinkedList& l, Node* node)
{
	if (l.start == NULL){l.start = node;l.end = node;}
	else{node->next = l.start; l.start = node;}
}

void Addend(LinkedList& l, Node* node)
{
	if (l.start == NULL){l.start = node; l.end = node;}
	else{l.end->next = node;l.end = node;}
}

void InsertAfterQ(LinkedList& l, Node* p, Node* q)
{
	if (q != NULL)
	{
	    cout<<1<<":T";
		p->next = q->next;
		q->next = p;
		if (l.end == q)
			l.end = p;
	}
	else
		Addend(l, p);
}

int Removestart(LinkedList& l, SinhVien& x)
{
	if (l.start != NULL)
	{
		Node* node = l.start;
		x = node->data;
		l.start = node->next;
		delete node;
		if (l.start == NULL)
			l.end = NULL;
		return 1;
	}
	return 0;
}

int RemoveAfterQ(LinkedList& l, Node* q, SinhVien& x)
{
	if (q != NULL)
	{
		Node* p = q->next;
		if (p != NULL)
		{
			if (l.end == p)
				l.end = q;
			q->next = p->next;
			x = p->data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}

Node* GetNode(LinkedList l, int index)
{
	Node* node = l.start;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->next;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;
}
void XuatNode(Node* node)
{

	cout << "ID: " << node ->data.MaSV << endl; 

    cout << "Full Name: " << node ->data.hoTen << endl;

    cout << "SEX: " << node ->data.gioiTinh << endl;

    cout << "Birthday: " << node ->data.ngaySinh.ngay << "/" << node ->data.ngaySinh.thang << "/" << node ->data.ngaySinh.nam << endl;

    cout << "Address: " << node ->data.diaChi << endl;

    cout << "Class: "  << node ->data.lop << endl;
	
    cout << "Department: " << node ->data.khoa << endl;
}
void PrintList(LinkedList l)
{
	if (l.start != NULL)
	{
		Node* node = l.start;
		while (node != NULL)
		{
            XuatNode(node);
			node = node->next;
		}
	}
}


Node* SearchInsert(LinkedList l, SinhVien x)
{
	Node* node = l.start;
	while (node != NULL && strcmp(node->data.MaSV,x.MaSV)<0){node = node->next;}
	if (node != NULL) return node;
	return NULL;
}
void SortList(LinkedList &list)
{
 	for(Node *pTmp=list.start;pTmp!=NULL;pTmp=pTmp->next)
 	{
   		for(Node *pTmp2=pTmp->next;pTmp2!=NULL;pTmp2=pTmp2->next)
  		{
			if(strcmp(pTmp->data.MaSV,pTmp2->data.MaSV)>0) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
			{
				SinhVien tmp=pTmp->data;
				pTmp->data=pTmp2->data;
				pTmp2->data=tmp;
			}
  		}
	 }
}

int Length(LinkedList l)
{
	int count = 0;
	Node* node = l.start;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}

void DestroyList(LinkedList& l)
{
	SinhVien x;
	Node* node = l.start;
	while (node != NULL)
	{
		Removestart(l, x);
		node = l.start;
	}
	l.end = NULL;
}
void NhapSv(SinhVien &sv)
{
    cout<<"ENTER STUDENT ID: ";fflush(stdin);gets(sv.MaSV);
    cout<<"ENTER FULL NAME: ";fflush(stdin);gets(sv.hoTen);
    cout<<"ENTER SEX: ";cin>>sv.gioiTinh;
    cout<<"ENTER BIRTHDAY: ";fflush(stdin);cin>>sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;
    cout<<"ENTER ADDRESS: ";fflush(stdin);gets(sv.diaChi);
    cout<<"ENTER CLASS: ";fflush(stdin);gets(sv.lop);
    cout<<"ENTER DEPARTMENT: ";fflush(stdin);gets(sv.khoa);
	cout<< endl;
}

void SinhViensameNgaySinh(LinkedList list)
{   int len=Length(list);
    bool Check[len]={};
    int i=0,j;
    bool checkNull=false;
    cout<<"LIST STUDENTS HAVING THE SAME BIRTHDAY"<<endl;
    for(Node *pTmp=list.start;pTmp!=NULL;pTmp=pTmp->next)
    {//for loop thứ hai
        bool checkdelete=false;
        j=i+1;
        if(!Check[i])
        {
            XuatNode(pTmp);
        }
        for(Node *pTmp2=pTmp->next;pTmp2!=NULL;pTmp2=pTmp2->next)
        {
            if(pTmp->data.ngaySinh.ngay==pTmp2->data.ngaySinh.ngay and !Check[j]) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
            { RemoveAfterQ(list,pTmp2,pTmp->data);
			 XuatNode(pTmp2);
			 Check[j]=true;
			 checkNull=true;
			 checkdelete=true;
            }
            j++;
        }
        if(checkdelete)
        {
            RemoveAfterQ(list,pTmp,pTmp->data);
        }
        i++;
        cout<<"-------------------------------------------------------"<<endl;

    }
    if(!checkNull)
    {
        cout<<"NO ANY STUDENTS HAVE THE SAME BIRTHDAY"<<endl;
    }
}
int main()
{
	LinkedList list;
	CreateList(list);
	Node* node;
    SinhVien sv;
    int len1;
    cout<<"ENTER THE NUMBER OF STUDENTS: ";cin>>len1;
	for (auto i = 1; i <=len1; i++)
	{
	    NhapSv(sv);
		node = CreateNode(sv);
		Addend(list, node);
	}
    SortList(list);
	PrintList(list);
	cout << endl;
	int len = Length(list);
	cout << "Length of list: " << len << endl;
	DestroyList(list);
	return 0;
}