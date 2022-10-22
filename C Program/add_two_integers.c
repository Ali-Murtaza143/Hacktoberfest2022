#include <stdio.h>
 
int main()
{
    int A, B, sum = 0;
 
    printf("Enter two numbers A and B : \n");
    scanf("%d%d", &A, &B);
    sum = A + B;

    printf("Sum of A and B is: %d", sum);
 
    return 0;
}
