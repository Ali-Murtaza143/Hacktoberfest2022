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
void generator(node *head,int len)
{
    while(len!=1)
    {
        head->next=new node();
        len--;
        head=head->next;
    }
    head->next=NULL;
}
node* rev_ll(node *head)
{
    node *current,*next,*prev;
    current=next=prev=head;
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
int ll_to_int(node *head)
{
    int sum=0;
    while(head!=NULL)
    {
        sum=sum*10+head->data;
        head=head->next;
    }
    return sum;
}
void int_to_ll(node *head,int sum)
{
    while(sum!=0)
    {
        head->data=sum%10;
        sum/=10;
        head=head->next;
    }
}
int main()
{
    node *head=new node(),*head2=new node(),*head3=new node(),*temp;
    int len,num1,num2,num3,temp_num,counter=0;
    cout<<"Enter length of first LL";
    cin>>len;
    cout<<"Enter data";
    cin>>head->data;
    generator_w_input(head,len);
    cout<<"Enter lenght of 2nd LL";
    cin>>len;
    cout<<"Enter data";
    cin>>head2->data;
    generator_w_input(head2,len);
    head=rev_ll(head);
    head2=rev_ll(head2);
    num1=ll_to_int(head);
    num2=ll_to_int(head2);
    num3=num1+num2;
    temp_num=num3;
    while(temp_num!=0)
    {
        temp_num/=10;
        counter++;
    }
    generator(head3,counter);
    int_to_ll(head3,num3);
    head3=rev_ll(head3);
    temp=head3;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    return 0;
}