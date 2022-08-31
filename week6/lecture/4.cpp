#include <iostream>
using namespace std;
long long hash(string s){
    long long p=31;
    long long hash=0,p_pow=1;
    for(int i=0;i<s.length();i++){
        hash+=(s[i]-'a'+1)*p_pow;
        p_pow*=p;
    }
    return hash;
}
int main(){
    string s;
    cin>>s;
    cout<<hash(s);
    return 0;
}