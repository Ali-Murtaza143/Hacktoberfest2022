#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
int front = -1, rear = -1;
int queue[MAX];
void enqueue(int);
void dequeue();
bool isFull();
bool isEmpty();
void displayQueue();
int main(){
   int choice, value;
   while(choice != 4){
      printf("\nPress 1 to Insert/Enqueue");
      printf("\nPress 2 to Delete/Dequeue");
      printf("\nPress 3 to display the queue");
      printf("\nPress 4 to Exit");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
         printf("\nEnter value to be inserted: ");
         scanf("%d", &value);
         enqueue(value);
         displayQueue();
         break;
      case 2:
         dequeue();
         displayQueue();
         break;
      case 3:
         displayQueue();
         break;
      case 4:
         exit(0);
         break;
      default:
         printf("Wrong choice entered!!\n");
         break;
      }
   }
   return 0;
}

void enqueue(int data){
   if(rear == MAX - 1){
      printf("Queue is Full\n");
   } else {
      if(front == -1){
         front = 0;
      }
      rear++;
      queue[rear] = data;
      printf("\nInserted value : %d", data);
   }
}
void dequeue(){
   if(isEmpty()){
      printf("Queue is Empty\n");
   } else {
      printf("\nDeleted value is: %d", queue[front]);
      front++;
      if(front > rear) front = rear = -1;
   }
}

bool isFull(){
   if(rear == MAX - 1){
      return true;
   } else {
      return false;
   }
}
bool isEmpty(){
   if(rear < front){
      return true;
   } else {
      return false;
   }
}
void displayQueue(){
   if(front == -1){
      printf("\nQueue is Empty");
      return;
   } 
   printf("\nElements in the queue are: ");
   for (int i = front; i <= rear; i++){
      printf("%d ", queue[i]);
   } 
   printf("\n");
}