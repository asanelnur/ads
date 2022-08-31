#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]) j=j+1;
        pi[i]=j;
    }
    for(int i=0;i<n;i++){
        cout<<pi[i]<<" ";
    }
    return 0;
}