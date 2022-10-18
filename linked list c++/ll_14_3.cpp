#include<iostream>
using namespace std;
class node
{
    public:
    int data=0;
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
node* ll_sum(node *head1,node *head2)
{
    int carry =0;
    node *head3 = new node();
    node *temp =head3;
    int val;
    while(head1!=NULL&&head2!=NULL)
    {
        val = head1->data+head2->data+carry;
        temp->data=val%10;
        if(val>9)
        {
            carry=1;
        }
        else{
            carry=0;
        }
        temp->next=new node();
        temp=temp->next;
        head1=head1->next;
        head2=head2->next;
        
    }
    while(head1!=NULL)
    {
        val=head1->data+carry;
        temp->data=val%10;
        if(val>9)
        {
            carry=1;
        }
        else{
            carry=0;
        }
        temp->next=new node();
        head1=head1->next;
        temp=temp->next;
    }
    while(head2!=NULL)
    {
        val=head2->data+carry;
        temp->data=val%10;
        if(val>9)
        {
            carry=1;
        }
        else{
            carry=0;
        }
        temp->next=new node();
        head2=head2->next;
        temp=temp->next;
    }
    if(carry!=0)
    {
        temp->data=carry;
        carry=0;
    }
    return head3;
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
    head3=ll_sum(head,head2);
    head3=rev_ll(head3);
    temp=head3;
    if(head3->data==0)
    {
        head3=head3->next;
        free(temp);
    }
    temp=head3;
    cout<<"\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    return 0;
}