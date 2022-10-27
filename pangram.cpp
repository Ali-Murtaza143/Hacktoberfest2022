//program to check whether a string is pangram or not
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	     int price[26];
	    for(int i=0;i<26;i++){
	        cin>>price[i];
	    }
	    string s;
	    cin>>s;
        int sum=0;
        for(int i=0;i<s.size();i++){
            price[s[i]-97]=0;
        }
        for(int i=0;i<26;i++){
                sum+=price[i];
            }
        
        cout<<sum<<endl;
	}
	return 0;
}
