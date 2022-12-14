#include <iostream>
using namespace std;
void h(string str,string pattern){
    long long n=str.length();
    long long h[n];
    long long q=(1<<32)-1;
    long long p[n];
    p[0]=1;

    for(long long i=1;i<n;i++){
        p[i]=(p[i-1]*31)%q;
    }

    for(long long i=0;i<n;i++){
        h[i]=((str[i]-'a'+1)*p[i])%q;
        if(i>0){
            h[i]+=h[i-1];
        }
        h[i]=h[i]%q;
    }
    long long ph=0;
    long long m=pattern.length();
    for(long long i=0;i<m;i++){
        ph=(ph+((pattern[i]-'a'+1)*p[i])%q)%q;
    }

    for(long long i=0;i+m-1<n;i++){
        long long j=i+m-1;
        long long cur=h[j];
        if(i>0){
            cur-=h[i-1];
        }
        if((ph*p[i])%q==cur && str.substr(i,m)==pattern){
            cout<<i<<" ";
        }
    }
}
int main(){
    string str,pattern;
    cin>>str>>pattern;
    h(str,pattern);
    return 0;
}