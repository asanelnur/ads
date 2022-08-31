#include <iostream>
using namespace std;
int get_min(int a[],int l,int r){
    int min=a[l];
    for(int i=l+1;i<r;i++){
        if(a[i]<min) min=a[i];
    }
    return min;
}
int main(){
    int n,k,min;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-k+1;i++){
        min=2147483647;
        for(int j = i; j < i+k ; ++j)
            if(min>a[j]){
                min = a[j];
            }
        cout<<min<<endl;
    }
    return 0;
}