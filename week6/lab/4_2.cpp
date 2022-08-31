#include <iostream>
#include <set>
using namespace std;
int main(){
    int n;
    cin>>n;
    int len,l;
    string s;
    
    long long p[10000];
    p[0]=1;
    for(int i=1;i<10000;i++){
        p[i]=p[i-1]*31;
    }
    for(int i=0;i<n;i++){
        cin>>len>>l;
        cin>>s;
        set<long long> myset;
        vector<long long> h(len);
        for(int i=0;i<len;i++){
            h[i]=(s[i]-'a'+1)*p[i];
            if(i>0){
                h[i]+=h[i-1];
            }
        }
        for(int i=0;i<len;i++){
            if()
        }
        cout<<myset.size()<<endl;
    }
    return 0;
}