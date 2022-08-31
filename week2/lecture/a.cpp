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
        sz++;
        node * temp=new node(x);
        if(head==NULL) head=tail=temp;
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
    void print(){
        node * temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
    node * find(int x){
        node * temp=head;
        node * res=NULL;
        while(temp!=NULL){
            if(temp->val==x){res=temp;break;};
            temp=temp->next;
        }
        return res;
    }
    void isexist(int x){
        node * current = find(x);
        if(current==NULL) cout<<"No";
        else cout<<"Yes";
    }
    void dl(node * n){
        if(n!=NULL){
            sz--;
            if(n->prev==NULL && n->next==NULL){
                head=tail=NULL;
            }else if(n->prev!=NULL && n->next!=NULL){
                n->prev->next=n->next;
                n->next->prev=n->prev;
            }else if(n->prev==NULL && n->next!=NULL){
                head=n->next;
                n->next->prev=NULL;
            }else if(n->prev!=NULL && n->next==NULL){
                tail=n->prev;
                n->prev->next=NULL;
            }
            delete n;
        }
    }
    void del(int x){
        node * temp=find(x);
        dl(temp);
    }
};
int main(){
    ll * l= new ll();
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        l->add(x);
    }
    l->print();
    //l->isexist(5);
    int m;
    cin>>m;
    l->del(m);
    l->print();
    return 0;
}