#include <iostream>
#include <vector>
using namespace std;

vector<int> f(string s){
    int m=s.length();
    vector<int> p(m);
    for(int i=1;i<m;i++){
        int j=p[i-1];
        while(j>0 && s[i]!=s[j]){
            j=p[j-1];
        }
        if(s[i]==s[j]) j++;
        p[i]=j;
    }
    return p;
}
int main(){
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();

    vector<int> p=f(t+"#"+s);

    for(int i=m;i<=n+m;i++){
        if(p[i]==m) cout<<i-2*m<<" ";
    }
    
    return 0;
}