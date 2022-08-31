#include <iostream>
#include <vector>
using namespace std;
void h(string s,string pattern){
    int n=s.length();
    long long h[n];
    long long p[n];
    p[0]=1;
    for(int i=1;i<n;i++){
        p[i]=p[i-1]*31;
    }
    for(int i=0;i<n;i++){
        h[i]=(s[i]-'a'+1)*p[i];
        if(i>0){
            h[i]+=h[i-1];
        }
    }

    int m=pattern.length();
    long long h_p=0;
    for(int i=0;i<m;i++){
        h_p+=(pattern[i]-'a'+1)*p[i];
    }

    for(int i=0;i+m-1<n;i++){
        long long cur=h[i+m-1];
        if(i>0){
            cur-=h[i-1];
        }
        if(h_p*p[i]==cur && s.substr(i,m)==pattern){
            cout<<i<<" ";
        }
    }
}
int main(){
    string s,p;
    cin>>s>>p;
    h(s,p);
    return 0;
}