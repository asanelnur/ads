#include <iostream>
using namespace std;
struct st{
    private:
    long long a[100000];
    long long topindex;
    long long firstindex;
    public:
    st(){
         topindex=50000;
         firstindex=50001;
    }
    void push_back(long long x){
        topindex++;
        a[topindex]=x;
    }
    void push_front(long long x){
        firstindex--;
        a[firstindex]=x;
    }
    bool notempty(){
        if(topindex>=firstindex) return true;
        return false;
    }
    long long pop_front(){
        if(notempty()==false) return 972939237;
        else{
            return a[firstindex];
        }
    }
    void popindexfront(){
        if(notempty()==true){
            firstindex++;
        }
    }
    long long pop_back(){
        if(notempty()==false) return 972939237;
        else{
            return a[topindex];
        }
    }
    void popindexback(){
        if(notempty()==true){
            topindex--;
        }
    }
    long long front(){
        if(notempty()==false) return 972939237;
        return a[firstindex];
    }
    long long back(){
        if(notempty()==false) return 972939237;
        return a[topindex];
    }
    void clear(){
        topindex=100;
        firstindex=101;
    }
    int size(){
        if(topindex>=firstindex) return topindex-firstindex+1;
        return 0;
    }

};
int main(){
    st s;
    string t;
    long long n;
    while(cin>>t){
        if(t=="push_front"){
            cin>>n;
            s.push_front(n);
            cout<<"ok"<<endl;
        }
        else if(t=="push_back"){
            cin>>n;
            s.push_back(n);
            cout<<"ok"<<endl;
        }
        else if(t=="pop_back"){
            if(s.pop_back()==972939237) cout<<"error"<<endl;
            else{
                cout<<s.pop_back()<<endl;
                s.popindexback();
            }
        }
        else if(t=="pop_front"){
            if(s.pop_front()==972939237) cout<<"error"<<endl;
            else{
                cout<<s.pop_front()<<endl;
                s.popindexfront();
            }
        }
        else if(t=="front"){
            if(s.front()==972939237) cout<<"error"<<endl;
            else cout<<s.front()<<endl;
        }
        else if(t=="back"){
            if(s.back()==972939237) cout<<"error"<<endl;
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