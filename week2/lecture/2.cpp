#include <iostream>
using namespace std;
struct node{
    int val;
    node * next;
    node(int x){
        val=x;
        next=NULL;
    }
    //node(int x):val(x),next(NULL){};
};
struct ll{
    node * head;
    node * tail;
    ll(){
        head=NULL;
        tail=NULL;
    }
    void add(int x){
        node * newNode=new node(x);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void print(){
        node * temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    int a[]={1,2,3,4,5,6,7};
    int n=sizeof(a)/sizeof(int);
    ll * l= new ll();
    for(int i=0;i<n;i++){
        l->add(a[i]);
    }
    l->print();
}