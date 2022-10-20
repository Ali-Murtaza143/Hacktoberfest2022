#include<stdio.h>
#include<stdlib.h>

int maximum(int a, int b){
    return (a > b)? a : b;
}

int lcs(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if (i == 0 || j == 0)
                L[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]){
                L[i][j] = L[i - 1][j - 1] + 1;
                printf("%c",X[i-1] );
            }
 
            else
                L[i][j] = maximum(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}
 

int main(){
  int n,m;
  scanf("%d" , &n );
  scanf("%d" , &m );

  char *a1 = (char*)malloc(n*sizeof(char)); 
  char *a2 = (char*)malloc(m*sizeof(char));
  scanf("%s" , a1);
  scanf("%s" , a2);
  printf("\n%d",lcs(a1 , a2 , n  , m));

}
