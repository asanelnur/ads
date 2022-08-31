#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long i,j=1,res=1,x,y;
    cin>>i;
    if(i==1){
        cout<<1;
        return 0;
    }
    long a=2;     // 1 2 3 4 5 6 
    long b=2;     // 1 2 3 4 
    while(1){    // 1 4 8 9 16 25 27 36
        x=pow(a,2);
        y=pow(b,3);
        if(x<y){
            res=x;
            a++;
            j++;
        }else if(y<x){
            res=y;
            b++;
            j++;
        }else{
            res=x;
            a++;
            b++;
            j++;
        }
        if(j==i){
            cout<<res<<endl;
            return 0;
        }
    }
    return 0;
}