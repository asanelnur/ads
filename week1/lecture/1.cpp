#include <iostream>
using namespace std;
struct st{
    int a[100];
    int topindex;
    st(){
        topindex=-1;
    }
    int top(){
        if(topindex==-1) return -1;
        return a[topindex];
    }
    void push(int x){
        topindex++;
        a[topindex]=x;
    }
    void pop(){
        if(topindex!=-1){
            topindex--;
        }
    }
};
int main(){
    st s;
    int d[]={1,10,2,3,5,4};
    int n=sizeof(d)/sizeof(int);
    for(int i=0;i<n;++i){
        s.push(d[i]);
    }
    //s.a[2]=3;
    for(int i=0;i<n;++i){
        cout<<s.top()<<endl;
        s.pop();
    }
    /*for(int i=0;i<n;++i){
        cout<<s.a[i]<<" ";
    }*/
    return 0;
}