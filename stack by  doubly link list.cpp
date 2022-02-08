#include<iostream>
#include<stdio.h>
using namespace std;
//stack by  doubly link list
class node
{
public:
    int info;
    node *next;
    node *prev;
};
node* creat(int data)
{
    node *ptr= new node;
    ptr->info=data;
    return ptr;
}
void display(node *head)
{
    node *ptr=head->next;
    while(ptr!=NULL)
    {
        cout<<" "<<ptr->info;
        ptr=ptr->next;
    }
}
void push(node *head,int data)
{
    node *ptr=head->next;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    node *p1=creat(data);
    ptr->next=p1;
    p1->prev=ptr;
    p1->next=NULL;
}
void pop(node *head)
{
    node *ptr=head->next;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    delete ptr->next->next;
    ptr->next=NULL;
}
int main()
{ 
   cout<<"=====stack by  doubly link list===="<<endl;
    node *head,*p1,*p2,*p3;
    head= new node;
    p1=creat(10);
    p2=creat(20);
    p3=creat(30);
    head->next=p1;

    p1->prev=head;
    p1->next=p2;

    p2->prev=p1;
    p2->next=p3;

    p3->prev=p2;
    p3->next=NULL;
    display(head);
    cout<<endl<<endl;
    pop(head);
    cout<<endl<<endl;
    display(head);
    return 0;
}
