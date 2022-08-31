#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		int k;
		cin>>s>>k;
	    int len = s.length();
	    vector<int> pi(len);
	    for(int i=1;i<len;i++){
	        int j = pi[i-1];
	        while(j>0 && s[i]!=s[j]){
	            j=pi[j-1];
			}
	        if(s[i]==s[j]){
	            j++;
			}
	        pi[i]=j;
	    }
	    cout<<(len+(len - pi[len-1])*(k - 1))<<endl;
	}
	return 0;
}