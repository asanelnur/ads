#include <iostream>
using namespace std;
struct heap{
    int val[100000];
    int hs;
    heap(){
        hs=0;
    }
    void add(int x){
        val[hs]=x;
        sift_up(hs);
        hs++;
    }
    int sift_up(int i){
        while(i!=0 && val[(i-1)/2]<val[i]){
            swap(val[(i-1)/2],val[i]);
            i=(i-1)/2;
        }
        return i;
    }
    int sift_down(int i){
        int res;
        if(2*i+1>hs-1){
            return i+1;
        }
        int c1=2*i+1;
        int c2=2*i+2;
        int mp=c1;
        if(c2<hs){
            if(val[c2]>val[c1]) mp=c2;
        }
        if(val[i]>val[mp]){
            return i+1;
        }
        if(val[mp]>val[i]){
            swap(val[mp],val[i]);
            res=sift_down(mp);
        }
        return res;

    }
    void swapp(int i,int k){
        val[i]=val[i]+k;
        int res=sift_up(i);
        cout<<res+1<<endl;
    }
    void print(){
        for(int i=0;i<hs;i++){
            cout<<val[i]<<" ";
        }
    }
};
int main(){
    heap h;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        h.add(k);
    }
    int m,x,y;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        h.swapp(x-1,y);
    }
    h.print();
    return 0;
}