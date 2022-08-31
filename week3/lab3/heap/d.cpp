#include <iostream>
using namespace std;
struct heap{
    int val[100000];
    int hs;
    heap(){
        hs=0;
    }
    int add(int x){
        val[hs]=x;
        int res=sift_up(hs);
        hs++;
        return res+1;
    }
    int sift_up(int i){
        while(i!=0 && val[i]>val[(i-1)/2]){
            swap(val[i],val[(i-1)/2]);
            i=(i-1)/2;
        }
        return i;
    }
    int sift_down(int i){
        int res=0;
        int c1=2*i+1;
        int c2=2*i+2;
        int mp=c1;
        if(c2<hs){
            if(val[c2]>val[c1]){
                mp=c2;
            }
        }
        if(val[i]>val[mp]){
            return res+1;
        }
        while((2*i+1)<hs && val[i]<val[mp]){
            swap(val[i],val[mp]);
            i=mp;
            res=i;
        }
        return res+1;
    }
    void extramax(){
        int min=val[0];
        if(hs==1){
            cout<<0<<" "<<min<<endl;
            hs--;
            return;
        }
        swap(val[0],val[hs-1]);
        hs--;
        int res=sift_down(0);
        cout<<res<<" "<<min<<endl;

    }
    void print(){
        for(int i=0;i<hs;i++){
            cout<<val[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    heap h;
    int n,m,k1,k2;
    cin>>n>>m;
    int cnt=0;
    for(int i=0;i<m;i++){
        cin>>k1;
        if(k1==2){
            cin>>k2;
            if(cnt<n){
                cnt++;
                cout<<h.add(k2)<<endl;
            }else{
                cout<<-1<<endl;
                continue;
            }
        }else if(k1==1){
            if(cnt==0){
                cout<<-1<<endl;
                continue;
            }else{
                h.extramax();
                cnt--;
            }
        }
    }
    h.print();
    return 0;
}