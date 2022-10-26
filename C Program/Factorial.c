// Factorial Program in C: Factorial of n is the product of all positive descending integers. Factorial of n is denoted by n!. For example:
// 5! = 5*4*3*2*1 = 120  
// 3! = 3*2*1 = 6

#include<stdio.h>  
int main()    
{    
 int i,fact=1,number;    
 printf("Enter a number: ");    
  scanf("%d",&number);    
    for(i=1;i<=number;i++){    
      fact=fact*i;    
  }    
  printf("Factorial of %d is: %d",number,fact);    
return 0;  
}   
