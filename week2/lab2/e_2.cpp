#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm>
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
    node * tail;
    node * head;
    int sz;
    ll(){
        head=tail=NULL;
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
        node * result=NULL;
        while(temp!=NULL){
            if(temp->val==x){
                result=temp;
                break;
            }
            temp=temp->prev;
        }
        return result;
    }
    bool findx(int x){
        node * temp=head;
        while(temp!=NULL){
            if(temp->val==x){
                return true;
            }
            temp=temp->prev;
        }
        return false;
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
    void print(){
        vector<int> ans;
        node * temp=head;
        ofstream outF;
        outF.open("output.txt");
        if(sz==0){
            outF<<"EMPTY"<<endl;
            outF.close();
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
};
int main(){
    ifstream in;
    in.open("input.txt");
    string str;
    int x=0;
    ll l;
    while(in>>str){
        for(int i=1;i<str.size();++i){
            x*=10;
            x+=int(int(str[i])-'0');
        }
        if(str[0]=='+'){
            l.add(x);
        }else if(str[0]=='-'){
            if(l.findx(x)==false){
                ofstream outF;
                outF.open("output.txt");
                outF<<"ERROR";
                outF.close();
                return 0;
            }else{
                l.dl(l.find(x));
            }
        }
        x=0;
    }
    l.print();
    return 0;
}