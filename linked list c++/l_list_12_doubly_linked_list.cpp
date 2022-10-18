#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next,*prev;
};
int generator(node *head,int len)
{
    node *temp=head;
    while(len!=1)
    {
        temp->next=new node();
        temp->next->prev=temp;
        cout<<"Enter data";
        cin>>temp->next->data;
        temp=temp->next;
        len--;
    }
    return 0;
}
int main()
{
    node *head=new node(),*temp,*last;
    head->prev=NULL;
    int len;
    cout<<"enter length of linked list";
    cin>>len;
    cout<<"Enter data";
    cin>>head->data;
    generator(head,len);
    
    temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data;
        last=temp;
        temp=temp->next;
    }
    temp=last;
    while (temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->prev;
    }
    return 0;
}