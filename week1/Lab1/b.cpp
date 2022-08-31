#include <iostream>
using namespace std;
struct st{
    int a[100000];
    int topindex=-1;
    int firstindex=0;
    /*st(){
         topindex=-1;
         firstindex=0;
    }*/
    void push(int x){
        topindex++;
        a[topindex]=x;
    }
    int notempty(){
        if(topindex>=firstindex) return 1;
        return 0;
    }
    int pop(){
        if(notempty()==0) return 0;
        else{
            return a[firstindex];
        }
    }
    void popindex(){
        if(notempty()==1){
            firstindex++;
        }
    }
    int front(){
        if(notempty()==0) return 0;
        return a[firstindex];
    }
    int clear(){
        topindex=-1;
        firstindex=0;
    }
    int size(){
        return topindex-firstindex+1;
    }

};
int main(){
    st s;
    string t;
    int n;
    while(cin>>t){
        if(t=="push"){
            cin>>n;
            s.push(n);
            cout<<"ok"<<endl;
        }
        else if(t=="pop"){
            if(s.pop()==0) cout<<"error"<<endl;
            else{
                cout<<s.pop()<<endl;
                s.popindex();
            }
        }
        else if(t=="front"){
            if(s.front()==0) cout<<"error"<<endl;
            else cout<<s.front()<<endl;
        }
        else if(t=="size"){
            cout<<s.size()<<endl;
        }
        else if(t=="clear"){
            s.clear();
            cout<<"ok"<<endl;
        }
        else if(t=="exit"){
            cout<<"bye"<<endl;
            break;
        }
    }
    return 0;
}