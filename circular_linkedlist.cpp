#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct node{
	int value;
	struct node* next;

};


struct node* insertAtbeg(struct node* ptr, int val){
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	struct node* temp2= (struct node*)malloc(sizeof(struct node));
	struct node* p= (struct node*)malloc(sizeof(struct node));
	temp->value=val;
	temp->next=ptr;
	p=ptr;
	do{
		temp2=ptr;
		ptr=ptr->next;
		
	}while(ptr!=p);
	temp2->next=temp;
	return temp;
}


struct node* insertAtend(struct node* ptr, int val){
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	struct node* p= (struct node*)malloc(sizeof(struct node));
	p=ptr;
	temp->value=val;
	do{
		ptr=ptr->next;
	}while(ptr->next!= p);
	ptr->next=temp;
	temp->next=p;
	return p;
}

struct node* insertAtX(struct node* ptr, int val, int pos){
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	struct node* p= (struct node*)malloc(sizeof(struct node));
	p=ptr;
	int count=0;
	temp->value=val;
	if(pos==0){
		ptr=insertAtbeg(ptr,val);
		return ptr;
	}
	else{
	while(count!= pos-1){
		ptr=ptr->next;
			count++;
	}
	temp->next=ptr->next;
	ptr->next=temp;

	}
	return p;	
}


void traversal(struct node* ptr){
	struct node * p;
	p=ptr;
	do{
		printf("%d ",ptr->value);
		ptr=ptr->next;
	}while(ptr!= p);
	cout<<endl;
}


void traversal_check(struct node* ptr){
	struct node * p;
	p=ptr;
	do{
		printf("%d ",ptr->value);
		ptr=ptr->next;
	}while(ptr!= p);
	printf("%d ",ptr->value);
	cout<<endl;
}

int main(){

struct node* head = (struct node*) malloc (sizeof(struct node));
head->value=10;
head->next=head;

head=insertAtend(head, 20);
traversal(head);
head=insertAtend(head, 30);
traversal(head);

head=insertAtend(head, 70);
traversal(head);

head=insertAtX(head, 17,3);
traversal(head);

head=insertAtbeg(head, 5);
traversal(head);

traversal_check(head);


	
}
