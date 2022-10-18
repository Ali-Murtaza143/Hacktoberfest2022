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
    node *head=new node(),*temp,*temp2;
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
    temp=head;
    temp2=head;
    while(temp2!=NULL&&temp2->next!=NULL)
    {
        temp2=temp2->next->next;
        temp=temp->next;
    }
    cout<<temp->data;
    return 0;
}