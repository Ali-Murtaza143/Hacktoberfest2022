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
    node *head;
    head = new node();
    node *one ;
    one = new node();
    node *two;
    two = new node();
    node *three;
    three = new node();
    node *four = new node();
    four = new node();
    node *last2=NULL,*last,*temp=head;
    head->next=one;
    one->next=two;
    two->next=three;
    three->next=four;
    four->next=NULL;
    head->data=1;
    one->data=2;
    two->data=3;
    three->data=4;
    four->data=5;
    //delete the last node
    last=head;
    while(last->next!=NULL)
    {
        last=temp->next;
        last2=temp;
        temp=temp->next;
    }
    last2->next=NULL;
    //
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    return 0;
}