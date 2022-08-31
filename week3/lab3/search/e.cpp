#include <iostream>
using namespace std;
int main(){
    int N,res,max_res=0,prev_max_res=-1;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>res;
        if(res>max_res){
            prev_max_res=max_res;
            max_res=res;
        }else if(res>prev_max_res && res<max_res){
            prev_max_res=res;
        }
    }
    cout<<prev_max_res;
    return 0;
}