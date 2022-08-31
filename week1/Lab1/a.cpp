#include <iostream>
using namespace std;
struct st{
    private:
    int a[100000];
    int topindex;
    int firstindex;
    public:
    st(){
        firstindex=50001;
        topindex=50000;
    }
    void push_front(int x){
        firstindex--;
        a[firstindex]=x;
    }
    void push_back(int x){
        topindex++;
        a[topindex]=x;
    }
    void pop_front(){
        cout<<a[firstindex]<<endl;
        firstindex++;
    }
    void pop_back(){
        cout<<a[topindex]<<endl;
        topindex--;
    }
    int front(){
        return a[firstindex];
    }
    int back(){
        return a[topindex];
    }
    int size(){
        return topindex-firstindex+1;
    }
    void clear(){
        topindex=50000;
        firstindex=50001;
    }
};
int main(){
    st s;
    string str;int x;
    while(1){
        cin>>str;
        if(str=="size"){
            cout<<s.size()<<endl;
        }else if(str=="push_back"){
            cin>>x;
            s.push_back(x);
            cout<<"ok"<<endl;
        }else if(str=="push_front"){
            cin>>x;
            s.push_front(x);
            cout<<"ok"<<endl;
        }
        else if(str=="pop_back"){
            if(s.size()>0){
                s.pop_back();
            }else{
                cout<<"error"<<endl;
            }
        }else if(str=="pop_front"){
            if(s.size()>0){
                s.pop_front();
            }else{
                cout<<"error"<<endl;
            }
        }
        else if(str=="front"){
            if(s.size()>0){
                cout<<s.front()<<endl;
            }else{
                cout<<"error"<<endl;
            }
        }else if(str=="back"){
            if(s.size()>0){
                cout<<s.back()<<endl;
            }else{
                cout<<"error"<<endl;
            }
        }else if(str=="clear"){
            s.clear();
            cout<<"ok"<<endl;
        }else{
            cout<<"bye"<<endl;
            break;
        }
    }
    return 0;
}