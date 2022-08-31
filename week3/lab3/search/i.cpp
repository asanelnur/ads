#include <iostream>
using namespace std;
void bs(int arr[],int l,int n,int x){
    int r=n-1;
    int left=0,right=0;
    while(l<=r){
        int m=l+(r-l)/2;
        if(arr[m]==x){
            left=m+1;
            r=m-1;
        }
        else if(arr[m]>x) r=m-1;
        else l=m+1;
    }
    if(left==0) cout<<0<<"\n";
    else{
        l=left-1;r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(arr[m]==x){
                right=m+1;
                l=m+1;
            }else if(arr[m]>x) r=m-1;
            else l=m+1;
        }
        cout<<left<<" "<<right<<endl;
    }
}
int main(){
    int n,k; 
    cin>>n>>k; 
    int a[n],b[k];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        cin>>b[i];
    }
    for(int i=0;i<k;i++){
        bs(a,0,n,b[i]);
    }
    return 0;
}