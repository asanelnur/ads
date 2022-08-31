#include <iostream>
#include <queue>
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
            if(q2.empty()) q2.push_front(x);
            else q1.push_front(x);
        }else if(s=='*'){
            cin>>x;
            q1.push_back(x);
        }else if(s=='-'){
            cout<<q2.back()<<endl;
            q2.pop_back();
        }
        if(q1.size()>q2.size()){
            q2.push_front(q1.back());
            q1.pop_back();
        }
    }
    return 0;
}