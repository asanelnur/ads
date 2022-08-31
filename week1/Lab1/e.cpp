#include <iostream>
#include <queue>
using namespace std;
deque<int> first,second;
void win_first(){
    first.push_back(first.front());
    first.push_back(second.front());
    first.pop_front();
    second.pop_front();
}
void win_second(){
    second.push_back(first.front());
    second.push_back(second.front());
    second.pop_front();
    first.pop_front();
}
int main(){
    int x;
    for(int i=0;i<5;i++){
        cin>>x;
        first.push_back(x);
    }
    for(int i=0;i<5;i++){
        cin>>x;
        second.push_back(x);
    }
    int cnt=0;
    while(1){
        if(first.size()==10){
            cout<<"first"<<" "<<cnt;
            return 0;
        }
        else if(second.size()==10){
            cout<<"second"<<" "<<cnt;
            return 0;
        }
        else if(cnt>1000000){
            cout<<"botva";
            return 0;
        }

        if(first.front()==0 and second.front()==9) win_first();
        else if(first.front()==9 and second.front()==0) win_second();
        else if(first.front()>second.front()) win_first();
        else if(first.front()<second.front()) win_second();
        cnt++;
    }
    return 0;
}