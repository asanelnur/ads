#include <iostream>
using namespace std;
bool h(string str,string pattern){
    int n=str.length();
    int h[n];
    int p[n];
    p[0]=1;
    for(int i=1;i<n;i++){
        p[i]=p[i-1]*31;
    }
    for(int i=0;i<n;i++){
        h[i]=(str[i]-'a'+1)*p[i];
        if(i>0){
            h[i]+=h[i-1];
        }
    }
    int ph=0;
    int m=pattern.length();
    for(int i=0;i<m;i++){
        ph+=(pattern[i]-'a'+1)*p[i];
    }

    bool res=false;
    for(int i=0;i+m-1<n;i++){
        int cur=h[i+m-1];
        if(i>0){
            cur-=h[i-1];
        }
        if(ph*p[i]==cur){
            cout<<i<<" ";
            res=true;
        }
    }
    cout<<endl;
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