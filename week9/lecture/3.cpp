/*
KMP
P[i]
S-> ab+"a"-> aba
s[i+1]=s[P[i]]  ==> P[i+1]=P[i]+1

       S[i]==S[j]
         j=P[i-1];
 P[i]=j+1        j=P[j-1]  while j!=0
abcacbd
0 0 0 1 2 3 0

*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> f(string s){
    int n=s.size();
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]) j=j+1;
        pi[i]=j;
    }
    return pi;
}
int main(){
    string s;
    cin>>s;
    vector<int> ans=f(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}