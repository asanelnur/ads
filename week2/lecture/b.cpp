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
    private:
    node * head;
    node * tail;
    public:
    ll(){
        head=NULL;
        tail=NULL;
    }
    void push(int x){
        node * item=new node(x);
        if(tail==NULL){
            head=tail=item;
        }else{
            tail->next=item;
            item->prev=tail;
            tail=item;
        }
    }
}
int main(){

    return 0;
}