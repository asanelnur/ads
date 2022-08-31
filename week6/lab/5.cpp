#include <iostream>
#include <map>
using namespace std;

long long h(string s){
    long long hash=0;
    long long p=1;
    for(int i=0;i<s.length();i++){
        hash+=(s[i]-'a'+1)*p;
        p*=31;
    }
    return hash;
}
int main(){
    int n;
    cin>>n;
    string s;

    map<long long,long long> v;

    for(int i=0;i<n;i++){
        cin>>s;
        long long hash=h(s);
        if(v[hash]==0){
            v[hash]++;
            cout<<"OK"<<endl;
        }else{
            cout<<s<<v[hash]<<endl;
            v[hash]++;
        }
    }
    return 0;
}