#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
void generator_w_input(node *head,int len)
{
    while(len!=1)
    {
        head->next=new node();
        cout<<"Enter data";
        cin>>head->next->data;
        head=head->next;
        len--;
    }
    head->next=NULL;
}
node* rev_ll(node *head)
{
    node *prev,*current,*next;
    prev=current=next=head;
    while(next!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head->next=NULL;
    return prev;
}
void sum_ll(node *head,node *head2,node *head3)
{
    int flag = 0;
    while(head!=NULL&&head2!=NULL)
    {
        if(head->data+head2->data>9)
        {
            head3->data=(head->data+head2->data)%10;
            head2->next->data+=1;
        }
        else
        {
            head3->data=head->data+head2->data;
        }
        head=head->next;
        head2=head2->next;
        head3->next=new node();
        head3=head3->next;
    }
    while(head!=NULL)
    {
        head3->next=new node();
        if(head3->data+head->data>=10)
        {
            head3->data=(head->data+head3->data)%10;
            if(head->next!=NULL)
            {
                head->next->data+=1;
            }
            else
            {
                head3->next->data+=1;
            }
            head3=head3->next;
        }
        else
        {
            head3->data+=head->data;
            head3=head3->next;
        }
        head2=head2->next;
    }
    while(head2!=NULL)
    {
        head3->next=new node();
        if(head3->data+head2->data>=10)
        {
            head3->data=(head2->data+head3->data)%10;
            if(head2->next!=NULL)
                head2->next->data+=1;
            else
                {
                head3->next->data+=1;
                }
            head3=head3->next;
        }
        else
        {
            head3->data+=head2->data;
            head3=head3->next;
        }
        head2=head2->next;
    }
}
int main()
{
    node *head=new node(),*head2=new node(),*head3=new node(),*temp;
    int len1,len2;
    cout<<"Enter length of first LL";
    cin>>len1;
    cout<<"Enter data";
    cin>>head->data;
    generator_w_input(head,len1);
    cout<<"Enter lenght of 2nd LL";
    cin>>len2;
    cout<<"Enter data";
    cin>>head2->data;
    generator_w_input(head2,len2);
    head=rev_ll(head);
    head2=rev_ll(head2);
    sum_ll(head,head2,head3);
    head3=rev_ll(head3);
    temp=head3;
    if(head3->data==0)
    {
        head3=head3->next;
        free(temp);
    }
    temp=head3;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    return 0;
}