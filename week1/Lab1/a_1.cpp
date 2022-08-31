#include <iostream>
using namespace std;
struct st{
    private:
    long long a[100000];
    long long topindex;
    public:
    st(){
        topindex=-1;
    }
    void push(int x){
        topindex++;
        a[topindex]=x;
    }
    long long pop(){
        if(topindex==-1) return 97313131;
        else{
            return a[topindex];
        }
    }
    void popindex(){
        topindex--;
    }
    long long back(){
        if(topindex==-1) return 97313131;
        return a[topindex];
    }
    long long size(){
        return topindex+1;
    }
    void clear(){
        topindex=-1;
    }
};
int main(){
    st s;
    string t;
    long long n;
    while(cin>>t){
        if(t=="push"){
            cin>>n;
            s.push(n);
            cout<<"ok"<<endl;
        }
        else if(t=="pop"){
            if(s.pop()==97313131) cout<<"error"<<endl;
            else{
                cout<<s.pop()<<endl;
                s.popindex();
            }
        }
        else if(t=="back"){
            if(s.back()==97313131) cout<<"error"<<endl;
            else cout<<s.back()<<endl;
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