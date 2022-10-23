// Sunny Number Or Not
#include <stdio.h>
#include <math.h>
int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);
    double root;
    root = sqrt(num + 1);
    if ((int)root == root)
        printf("It is a Sunny Number.");
    else
        printf("It is not a Sunny Number.");
}