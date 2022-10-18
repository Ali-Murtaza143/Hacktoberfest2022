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
    return 0;
}
int generator(node *head,int len)
{
    node *temp=head;
    while(len!=1)
    {
        temp->next=new node();
        temp=temp->next;
        len--;
    }
    return 0;
}
int main()
{
    node *head1=new node(),*head2=new node(),*head3=new node(),*temp1,*temp2,*temp3;
    int len,len2;
    cout<<"Enter the length of 1st linked list";
    cin>>len;
    cout<<"Enter data";
    cin>>head1->data;
    generator_w_input(head1,len);
    cout<<"Enter the length of 2nd linked list";
    cin>>len2;
    cout<<"Enter data";
    cin>>head2->data;
    generator_w_input(head2,len2);
    generator(head3,len+len2);
    temp1=head1;
    temp2=head2;
    temp3=head3;
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            temp3->data=temp1->data;
            temp1=temp1->next;
        }
        else 
        {
            temp3->data=temp2->data;
            temp2=temp2->next;
        }
        temp3=temp3->next;
    }
    if(temp1!=NULL)
    {
        while(temp1!=NULL)
        {
        temp3->data=temp1->data;
        temp1=temp1->next;
        temp3=temp3->next;
        }
    }
    else
    {
        while(temp2!=NULL)
        {
        temp3->data=temp2->data;
        temp2=temp2->next;
        temp3=temp3->next;
        }
    }
    temp3=head3;
    while(temp3!=NULL)
    {
        cout<<temp3->data;
        temp3=temp3->next;
    }
    /*cout<<"list 1"<<"\n";
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<"\n";
    cout<<"list 2"<<"\n";
    temp=head2;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }*/
    return 0;
}