#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
int generator_w_input(node *head,int len)
{
    node *temp=head;
    while(len!=1)
    {
        temp->next=new node();
        cout<<"Enter data";
        cin>>temp->next->data;
        temp=temp->next;
        len--;
    }
    temp->next=NULL;
    return 0;
}
int main()
{
    node *head=new node(),*current,*prev,*next;
    int len;
    cout<<"Enter length";
    cin>>len;
    cout<<"Enter data";
    cin>>head->data;
    generator_w_input(head,len);

    //reverse a linked list

    current=head;
    prev=head;
    next=head;
    while(next!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head->next=NULL;
    head=prev;
    current=head;
    while(current!=NULL)
    {
        cout<<current->data;
        current=current->next;
    }
    return 0;
}