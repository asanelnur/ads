#include <iostream>
using namespace std;
struct heap{
    int val[100];
    int hp;
    heap(){
        hp=0;
    }
    int get_min(){
        return val[0];
    }
    void add(int x){
        int i=hp;
        val[i]=x;
        hp++;
        int p=(i-1)/2;
        while(i!=0 && val[i]<val[p]){
            swap(val[i],val[p]);
            i=p;
            p=(i-1)/2;
        }
    }
    void print(){
        for(int i=0;i<hp;i++){
            cout<<val[i]<<" ";
        }
    }
};
int main(){
    heap h;
    int arr[]={1,6,8,8,7,12,9};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        h.add(arr[i]);
    }
    cout<<h.get_min()<<endl;
    h.print();
    h.add(5);
    cout<<endl;
    h.print();
    return 0;
}