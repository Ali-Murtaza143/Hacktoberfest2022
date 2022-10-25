#include<stdio.h>  
#include<stdlib.h>  
struct node{  
    struct node *prev, *next;  
    int data;  
};

struct node *head;
void insertion_beginning();  
void insertion_last();  
void insertion_after();
void insertion_before();  
void deletion_beginning();  
void deletion_last();  
void deletion_specified();  
void display();

int main (){  
   int choice1 = 0, data, choice2, value, location;  
   while(choice1 != 4){
      printf("\n~~~~DLL Menu by Sourasish~~~~\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
      scanf("%d",&choice1);
      switch(choice1){
         case 1:
            while(1){
               printf("\nSelect from the following Inserting options\n");
               printf("1. Insertion at Beginning\n2. Insertion at End\n3. Insert After\n4. Insert Before\n5. Cancel\nEnter your choice: ");
               scanf("%d",&choice2);
               switch(choice2){
                  case 1:
                     insertion_beginning();
                     display();
                     break;
                  case 2: 	
                     insertion_last();
                     display();
                     break;
                  case 3:
                     insertion_after();
                     display();
                     break;
                  case 4:
                     insertion_before();
                     display();
                     break;
                  case 5:
                     goto EndSwitch;
                  default:
                     printf("\nPlease select correct Inserting option!\n");
               }
            }
         case 2:
            while(1){
               printf("\nSelect from the following Deleting options\n");
               printf("1. Delete from Beginning\n2. Delete from End\n3. Delete a specific node\n4. Cancel\nEnter your choice: ");
               scanf("%d", &choice2);
               switch(choice2){
                  case 1:
                     deletion_beginning();
                     display();
                     break;
                  case 2:
                     deletion_last();
                     display();
                     break;
                  case 3:
                     deletion_specified();
                     display();
                     break;
                  case 4:
                     goto EndSwitch;
                  default:
                     printf("\nPlease select correct Deleting option!\n");
               }
            }
            EndSwitch: break;
         case 3: 
            display();
         	break;
         case 4: 
            exit(0);
         default:
            printf("\nPlease select correct option!");
      }
   }
   return 0;
}

void insertion_beginning(){
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL){  
      printf("\nOVERFLOW");  
   } else{  
      printf("\nEnter value: ");  
      scanf("%d",&item);  
      if(head==NULL) {  
         ptr->next = NULL;  
         ptr->prev=NULL;  
         ptr->data=item;  
         head=ptr;  
      }else {  
         ptr->data=item;  
         ptr->prev=NULL;  
         ptr->next = head;  
         head->prev=ptr;  
         head=ptr;  
      }  
      printf("\nNode inserted\n");
   }
}  
void insertion_last() {  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL){  
       printf("\nOVERFLOW");  
   } else{  
      printf("\nEnter value: ");  
      scanf("%d",&item);  
      ptr->data=item;  
      if(head == NULL){  
         ptr->next = NULL;  
         ptr->prev = NULL;  
         head = ptr;  
      }else {  
         temp = head;  
         while(temp->next!=NULL)  
            temp = temp->next;
         temp->next = ptr;  
         ptr ->prev=temp;  
         ptr->next = NULL;  
      }  
      printf("\nNode inserted!\n");       
   }   
}  
void insertion_after(){  
   struct node *ptr,*temp;  
   int item,loc,i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL){  
       printf("\n OVERFLOW");  
   } else{  
      temp=head;  
      printf("Enter the location: ");  
      scanf("%d", &loc);  
      for(i=0;i<loc;i++){  
         temp = temp->next;  
         if(temp == NULL){  
            printf("\nThere are less than %d elements", loc);  
            return;  
         }  
      }  
      printf("Enter value: ");  
      scanf("%d", &item);  
      ptr->data = item;  
      ptr->next = temp->next;  
      ptr -> prev = temp;  
      temp->next = ptr;  
      temp->next->prev=ptr;  
      printf("\nnode inserted\n");  
   }  
}

void insertion_before(){  
   struct node *ptr, *temp;  
   int item, loc, i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL){  
       printf("\n OVERFLOW");  
   } else{  
      temp=head;  
      printf("Enter the location: ");  
      scanf("%d", &loc);  
      for(i=0; i <= loc; i++)
         temp = temp->next;   
      printf("Enter value: ");  
      scanf("%d", &item);  
      ptr->data = item;  
      ptr->next = temp;
      temp->prev = ptr;  
      ptr -> prev = temp->prev;  
      temp->prev->next =ptr; 
      printf("\nNode inserted\n");  
   }  
}

void deletion_beginning(){  
   struct node *ptr;  
   if(head == NULL){  
      printf("\n UNDERFLOW");  
   } else if(head->next == NULL){  
      head = NULL;   
      free(head);  
      printf("\nnode deleted\n");  
   } else{  
      ptr = head;  
      head = head -> next;  
      head -> prev = NULL;  
      free(ptr);  
      printf("\nnode deleted\n");  
   }  
}  

void deletion_last(){  
   struct node *ptr;  
   if(head == NULL){  
      printf("\n UNDERFLOW");  
   } else if(head->next == NULL){  
      head = NULL;   
      free(head);   
      printf("\nnode deleted\n");  
   }else {  
      ptr = head;   
      if(ptr->next != NULL){  
         ptr = ptr -> next;   
      }  
      ptr -> prev -> next = NULL;   
      free(ptr);  
      printf("\nnode deleted\n");  
   }  
}  
void deletion_specified(){  
   struct node *ptr, *temp;  
   int val;  
   printf("\nEnter the data after which the node is to be deleted: ");  
   scanf("%d", &val);  
   ptr = head;  
   while(ptr -> data != val)
      ptr = ptr -> next;  
   if(ptr -> next == NULL){  
      printf("\nCan't delete\n");  
   } else if(ptr -> next -> next == NULL){  
      ptr ->next = NULL;  
   } else{   
      temp = ptr -> next;  
      ptr -> next = temp -> next;  
      temp -> next -> prev = ptr;  
      printf("\nnode deleted\n");  
      free(temp);  
   }     
}  
void display(){
   if(head == NULL){
      printf("\nList is Empty");
      return;
   }
   struct node *ptr;  
   printf("\nThe DLL is: ");  
   ptr = head;  
   while(ptr != NULL){  
      printf("%d ", ptr->data); 
      ptr=ptr->next;  
   }
   printf("\n");
} 




