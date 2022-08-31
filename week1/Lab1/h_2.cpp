#include <iostream>
#include <deque>
using namespace std;
int main(){
    int N,x;
    char s;
    cin>>N;
    deque<int> q1,q2;
    for(int i=0;i<N;i++){
        cin>>s;
        if(s=='+'){
            cin>>x;
            if(q2.empty()) q2.push_front(x);//q1:5,3
            else q1.push_back(x);          //q2:1,2
        }else if(s=='*'){
            cin>>x;
            q1.push_front(x);
        }else if(s=='-'){
            cout<<q2.front()<<endl;
            q2.pop_front();
        }
        if(q1.size()>q2.size()){
            q2.push_back(q1.front());
            q1.pop_front();
        }
    }
    return 0;
}