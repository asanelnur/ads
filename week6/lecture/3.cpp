#include <iostream>
using namespace std;
bool h(string str,string pattern){
    long long n=str.length();
    long long h[n];
    long long q=(1<<30)+1;
    long long p[n];
    p[0]=1;

    for(long long i=1;i<n;i++){
        p[i]=(p[i-1]*31)%q;  // 31 саныны кирилица немесе баска к-п арип болганда улкен жай санга озгерту керек
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

    bool res=false;
    for(long long i=0;i+m-1<n;i++){
        long long j=i+m-1;
        long long cur=h[j];
        if(i>0){
            cur-=h[i-1];
        }
        //H i>>j=Si*p^0+Si+1*P^1+
        //H i..j=Si*p^i+Si+1*p^i+1+ 
        if((ph*p[i])%q==cur && str.substr(i,m)==pattern){
            res=true;
            break;
        }
    }
    return res;
}
int main(){
    string str,pattern;
    cin>>str>>pattern;
    cout<<h(str,pattern);
    return 0;
}

/*
s1 s2 s3 s4 s5 ... sn ->text
t1 t2 t3 ->pattern 
h(sx...sy)=h(t)
h[i ... j]=Si+S(i+1)*P+S(i+2)*P^2+ ... + Sj*P^(j-i);

h[i...j]=h[0...j]-h[0...i-1]/p^i;

prefics: hello -> h,he,hel,hell,hello
*/