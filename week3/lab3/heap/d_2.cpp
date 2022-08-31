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
        cout<<sift_up(hs)+1<<endl;
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
        for(int i=0;i<hs;i++)
            cout<<val[i]<<" ";
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
                h.add(k2);
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