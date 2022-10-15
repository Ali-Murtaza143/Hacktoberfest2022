#include<iostream>
using namespace std;
int binarysearch(int arr[],int n, int k){
int s = 0;
int e = n;
while(s<=e){
    int mid = s+e/2;
    if (arr[mid]==k){
        return mid;
    }
    else if(arr[mid]>k){
        e=mid-1;
    }
    else{
        s=mid+1;
    }
}
return -1;
}
int main()
{
    int n;
    int k;
    cout<<"enter no. of elements to insert"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter key"<<endl;
    cin>>k;
    cout<<binarysearch(arr,n,k);
}
