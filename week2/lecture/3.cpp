#include <iostream>
using namespace std;
struct node{
    int val;
    node * next;
    node * prev;
    node(int x){
        val=x;
        next=NULL;
        prev=NULL;
    }
    //node(int x):val(x),next(NULL),prev(NULL){}
};
struct ll{
    node * head;
    node * tail;
    int sz;
    ll(){
        head=NULL;
        tail=NULL;
        sz=0;
    }
    void add(int x){
        node * newNode=new node(x);
        sz++;
        if(head==NULL) head=tail=newNode;
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    void print1(){
        node * temp=tail;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }
    void print2(){
        node * temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    bool isEmpty(){
        return sz==0;
    }
};
int main(){
    ll * l=new ll();
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(a) / sizeof(int);
    for(int i = 0; i < n; ++i){
        l->add(a[i]);
    }
    l->print1();
    l->print2();
    return 0;
}