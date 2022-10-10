//Armstrong number: An armstrong number of order 'n' is a number in which each digit when multiplied by itself n number of times and finally added together,
//results the same number.
//Ex: 371 is a 3-digit number i.e. of order 3
//So, 3*3*3 + 7*7*7 + 1*1*1 = 27+343+1 = 371

#include<stdio.h>
#include<conio.h>
int main(){
  int number,count=0,result=0,mul=1,cnt,rem;
  printf("Please enter a number:");
  scanf("%d",&number);
  int q=number;
  while(q!=0){
    q=q/10;
    count++;
  }
  cnt=count;
  q=number;
  while(q!=0){
    rem=q%10;
    while(cnt!=0){
      mul=mul*rem;
      cnt--;
    }
    result=result+mul;
    cnt=count;
    q=q/10;
    mul=1;
  }
  if(result==number)
    printf("%d is Armstrong number",number);
  else
    printf("%d is not Armstrong number",number);
  return 0;
}
