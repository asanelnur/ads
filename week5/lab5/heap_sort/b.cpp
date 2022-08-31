#include <iostream>
using namespace std;
struct heap{
    int val[100000];
    int hp;
    heap(){
        hp=0;
    }
    int get_max(){
        return val[0];
    }
    void add(int x){
        int i=hp;
        val[i]=x;
        hp++;
        int p=(i-1)/2;
        while(i!=0 && val[i]>val[p]){
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
                 if(val[c2]>val[c1]) mp=c2;
             } 
             if(val[i]<val[mp]){
                 swap(val[i],val[mp]);
                 i=mp;
             }else{
                 break;
             }
        }
    }
};
int main(){
    heap h;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k==0){
            int x;
            cin>>x;
            h.add(x);
        }else if(k==1){
            cout<<h.get_max()<<endl;
            h.del();
        }
    }
    return 0;
}