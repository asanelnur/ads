#include <iostream>
#include <queue>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    deque<int> mydq;
    for(int i=0;i<str.size();i++){
        if(str[i]=='+' or str[i]=='-' or str[i]=='*'){
            int x=mydq.front();
            mydq.pop_front();
            int y=mydq.front();
            mydq.pop_front();
            if(str[i]=='+') mydq.push_front(y+x);
            else if(str[i]=='-') mydq.push_front(y-x);
            else if(str[i]=='*') mydq.push_front(y*x);
        }else if(str[i]!=' '){
            mydq.push_front(int(str[i]-48));
        }
    }
    cout<<mydq.front();
    return 0;
}