#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    struct node *ptr;
    ptr = head;
   
   for (int i = 0; i < 10; i++)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
        printf("\n");

}

struct node * insertionAtBeg(struct node *head)
{
    struct node *trav;
    trav = head;
    struct node *insertionAtBeg = (struct node *)malloc(sizeof(struct node));
    insertionAtBeg->data = 9;
    insertionAtBeg->next = trav->next;
    trav->next = insertionAtBeg;

    head = trav;
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = NULL;

    head->next = NULL;

    struct node *first = (struct node *)malloc(sizeof(struct node));
    head->next = first;
    first->next = head;
    first->data = 1;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    first->next = second;
    second->next = head;
    second->data = 2;

    // display(head);
   head = insertionAtBeg(head);
    display(head);
}