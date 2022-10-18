#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
int main()
{
    node *head=new node(),*temp;
    node *one=new node();
    node *two=new node();
    node *three=new node();
    node *four=new node();
    node *five=new node();
    head->data=0;
    one->data=1;
    two->data=2;
    three->data=3;
    four->data=4;
    five->data=5;
    head->next=one;
    one->next=two;
    two->next=three;
    three->next=four;
    four->next=five;
    five->next=NULL;
    //find the mid of the linked list
    int len;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    len=len/2;
    temp=head;
    for(int i=0;i<len;i++)
    {
        temp=temp->next;
    }
    //
    cout<<temp->data;
    return 0;
}