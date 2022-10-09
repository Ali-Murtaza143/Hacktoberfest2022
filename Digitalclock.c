#include <stdio.h>
#include <time.h> //for sleep() function
#include <unistd.h>
#include <stdlib.h>
 
int main()
{
    int h, m, s;
     
    h=m=s=0;
 
    while(1)
    {
        //clear output screen
        system("clear");
         
        //print time in HH : MM : SS format
        printf("%02d : %02d : %02d ",h,m,s);
         
         //clear output buffer in gcc
        fflush(stdout);
         
         //increase s
        s++;
 
        //update h,m and s
        if(s==60){
            m+=1;
            s=0;
        }
        if(m==60){
            h+=1;
            m=0;
        }
        if(h==24){
            h=0;
            m=0;
            s=0;
        }
         
        sleep(1);   //wait till 1 s
    }
 
    return 0;
}
