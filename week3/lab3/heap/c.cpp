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
    void sift_up(int i){
        while(i!=0 && val[(i-1)/2]<val[i]){
            swap(val[(i-1)/2],val[i]);
            i=(i-1)/2;
        }
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
    void extramax(){
        int min=val[0];
        swap(val[0],val[hs-1]);
        hs--;
        int res=sift_down(0);
        cout<<res<<" "<<min<<endl;
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
    for(int i=0;i<n-1;i++){
        h.extramax();
    }
    return 0;
}