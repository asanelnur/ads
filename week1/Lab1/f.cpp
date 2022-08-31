#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<char> st;
    string s;
    cin>>s;
    for(long unsigned i=0;i<s.size();i++){
        if(s[i]=='(') st.push(')');
        else if(s[i]=='[') st.push(']');
        else if(s[i]=='{') st.push('}');
        else{
            if(s[i]==st.top()) st.pop();
            else{
                cout<<"no";
                return 0;
            }
        }
    }
    if(st.empty()) cout<<"yes";
    else cout<<"no";
    return 0;
}