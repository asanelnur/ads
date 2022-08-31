#include <iostream>
using namespace std;
struct st{
    int *a;
    int topindex;
    st(int n){
        a= new int[n];
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
    int d[]={1,10,2,3,5,4,2,3,4,5,67,89,3,2,1};
    int n=sizeof(d)/sizeof(int);
    st s(n);
    for(int i=0 ; i<n ; ++i){
        s.push(d[i]);
    }

    for(int i=0; i<n ; ++i){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}