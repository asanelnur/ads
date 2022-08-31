#include <iostream> 
using namespace std; 
struct st {    
    long long s[100]; 
    int cursor=0;  
    void push(long long n){
        s[cursor++]=n; 
    } 
    long long pop(){ 
        return s[--cursor]; 
    } 
    long long back(){ 
        return s[cursor-1]; 
    } 
    unsigned size(){ 
        return cursor; 
    } 
    void clear(){ 
        cursor=0; 
        s[cursor]=0; 
    } 
}; 
int main() { 
    st x; 
    string b;   
    long long n; 
    while(cin>>b){   
        if(b=="push"){    
            cin>>n; 
            x.push(n); 
            cout<<"ok"<<endl; 
        } 
        else if(b=="pop"){ 
            if(x.size()==0){
                cout<<"error"<<endl;
            }
            else
                cout<<x.pop()<<endl; 
        } 
        else if(b=="back"){ 
                if(x.size()==0){
                cout<<"error"<<endl;
            }
            else cout<<x.back()<<endl;  
        } 
        else if(b=="size"){ 
        cout<<x.size()<<endl; 
        } 
        else if(b=="clear"){ 
            x.clear(); 
            cout<<"ok"<<endl; 
        } 
        else if(b=="exit"){ 
            cout<<"bye"<<endl; 
            break; 
        } 
    } 
    return 0; 
}