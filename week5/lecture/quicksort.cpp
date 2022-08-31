#include <iostream>
using namespace std;
int partition(int arr[],int l,int r){
    int  pivot=arr[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void quicksort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
}
int main(){
    int a[]={10,80,30,90,40,50,70};
    int n=sizeof(a)/sizeof(int);
    quicksort(a,0,n-1);
    print_array(a,n);
    return 0;
}