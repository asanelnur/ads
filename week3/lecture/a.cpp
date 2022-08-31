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
    void del(){
        val[0]=val[--hp];
        int i=0;
        while((2*i+1)<hp){
            int c1=2*i+1;
            int c2=2*i+2;
            int mp=c1;
            if(c2<hp){
                if(val[c2]<val[mp]) mp=c2;
            }
            if(val[i]>val[mp]){
                swap(val[i],val[mp]);
                i=mp;
            }else{break;}        
        }
    }
    void print(){
        for(int i=0;i<hp;i++){
            cout<<val[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    int a[]={1,6,8,8,7,12,9};
    int n=sizeof(a)/sizeof(int);
    heap h;
    for(int i=0;i<n;i++){
        h.add(a[i]);
    }
    for(int i=0;i<n;i++){
        cout<<h.get_min()<<" ";
        h.del();
    }
    return 0;
}