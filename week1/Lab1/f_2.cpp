#include <iostream>
using namespace std;
char c[100000];
long long index=0;
int main(){
    string s;
    cin>>s;
    for(long unsigned i=0;i<s.size();i++){
        if(s[i]=='(')  c[++index]=')';
        else if(s[i]=='[') c[++index]=']';
        else if(s[i]=='{') c[++index]='}';
        else{
            if(s[i]==c[index]) index--;
            else{
                cout<<"no";
                return 0;
            }
        }
    }
    if(index==0) cout<<"yes";
    else cout<<"no";
    return 0;
}