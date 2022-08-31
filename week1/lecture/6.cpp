#include <iostream>
using namespace std;
struct st{
    private:
    int a[100];
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
    int isempty(){
        if(topindex<firstindex) return 1;
        return 0;
    }
    int pop(){
        if(isempty()==1) return 1;
        else{
            return a[firstindex++];
        }
    }
    int size(){
        return topindex-firstindex+1;
    }

};
int main(){
    st s;
    int d[]={1,2,3,4,5,6,7};
    int n=7;
    for(int i=0;i<n;i++){
        s.push(d[i]);
    }
    cout<<s.size()<<endl;
    while(!s.isempty()){
        cout<<s.pop()<<endl;
    }
    return 0;
}