#include <iostream>
using namespace std;
void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[m+1+j];
    }
    i=0,j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void print_sum(int arr[],int n){
    int sum=0;
    int sumofelements=arr[0];
    for(int i=1;i<n;i++){
        sumofelements+=arr[i];
        sum+=sumofelements;
    }
    cout<<sum;   
}
void print_array(int arr[],int n){
for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    print_array(a,n);
    print_sum(a,n);
    return 0;
}