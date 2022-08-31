#include <iostream>
using namespace std;
struct st{
    private:
    int a[100000];
    int topindex;
    int firstindex;
    public:
    st(){
         topindex=-1;
         firstindex=0;
    }
    void push(int x){
        topindex++;
        a[topindex]=x;
    }
    int notempty(){
        if(topindex>=firstindex) return true;
        return false;
    }
    int pop(){
        if(notempty()==false) return 972939237;
        else{
            return a[firstindex];
        }
    }
    void popindex(){
        if(notempty()==true){
            firstindex++;
        }
    }
    int front(){
        if(notempty()==false) return 972939237;
        return a[firstindex];
    }
    void clear(){
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
            if(s.pop()==972939237) cout<<"error"<<endl;
            else{
                cout<<s.pop()<<endl;
                s.popindex();
            }
        }
        else if(t=="front"){
            if(s.front()==972939237) cout<<"error"<<endl;
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