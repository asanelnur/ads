#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mxsize(string s){
    int n=s.size();
    vector<int> pi(n);
    int mx=0;
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]) j=j+1;
        pi[i]=j;
        mx=max(mx,pi[i]);
    }
    return mx;
}
int main(){
    int Q;cin>>Q;
    while(Q>0){
        string str;
        cin>>str;
        int k=0;
        int n=str.size();
        string t;
        for(int i=0;i<n;i++){
            t+=str[i];
            reverse(t.begin(),t.end());
            k+=t.length()-mxsize(t);
            reverse(t.begin(),t.end());
        }
        cout<<k<<endl;
        Q--;
    }
    return 0;
}