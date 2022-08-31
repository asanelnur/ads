#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
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
    bool err=false;
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
    node *find(int x){
        node * temp=head;
        node * ansult=NULL;
        while(temp!=NULL){
            if(temp->val==x){
                ansult=temp;
                break;
            }
            temp=temp->next;
        }
        return ansult;
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
    void dl(int x){
        node * temp=find(x);
        if(find(x)==NULL){
            ofstream outF;
            outF.open("output.txt");
            outF<<"ERROR"<<endl;
            outF.close();
            err=true;
        }else dl(temp);
    }
    void print(){
        vector<int> ans;
        node * temp=head;
        ofstream outF;
        outF.open("output.txt");
        if(isEmpty()){
            outF<<"EMPTY"<<endl;
        }else{
             while(temp!=NULL){
                 ans.push_back(temp->val);
                 temp=temp->next;
             }
             sort(ans.begin(),ans.end());
             vector<int > :: iterator it;
             for(it=ans.begin();it!=ans.end();++it){
                outF<<*it<<" ";
             }
             outF.close();
        }
    }
    bool isEmpty(){
        return sz==0;
    }
};
int main(){
    ifstream in;
    in.open("input.txt");
    string str;
    ll l;
    int x=0;
    while(in>>str){
        for(int i=1;i<str.size();++i){
            x*=10;
            x+=int(int(str[i])-'0');
        }
        if(str[0]=='+'){
            l.add(x);
        }else if(str[0]=='-'){
            l.dl(x);
            if(l.err)
                return 0;
        }
        x=0;
    }
    l.print();
    return 0;
}