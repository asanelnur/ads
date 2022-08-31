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
    string s,p;
    cin>>s>>p;
    vector<int> pi;
    int l=s.length();
    int m=p.length();
    if(l>m){
        string str=p+"#"+s;
        pi=f(str);
        
    }
    return 0;
}