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
    node *head=new node(),*temp,*temp2,*head_rev;
    int len;
    cout<<"Enter length";
    cin>>len;
    cout<<"Enter data";
    cin>>head->data;
    generator_w_input(head,len);

    //reverse a linked list

    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    head_rev=temp;
    temp=head;
    while(len!=0)
    {
        temp=head;
        while(temp->next!=NULL&&temp->next->next!=temp)
        {
            temp2=temp;
            temp=temp->next;
        }
        temp->next=temp2;
        len--;
    }
    temp->next=NULL;
    while(head_rev!=NULL)
    {
        cout<<head_rev->data;
        head_rev=head_rev->next;
    }
    return 0;
}