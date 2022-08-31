#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
vector<pair<string,int> > ans;
struct node{
    string str;
    int val;
    node * next;
    node(string s){
        str=s;
        val=1;
        next=NULL;
    }
};
struct ll{
    node * head;
    node * tail;
    ll(){
        head=NULL;
        tail=NULL;
    }
    void add(string s){
        node * newNode=new node(s);
        if(head==NULL) head=tail=newNode;
        else if(find(s)!=NULL) find(s)->val++;
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    node *find(string s){
        node * temp=head;
        node * result=NULL;
        while(temp!=NULL){
            if(temp->str==s){
                result=temp;
                break;
            }
            temp=temp->next;
        }
        return result;
    }
    void ddd(){
        node * temp=head;
        while(temp!=NULL){
            ans.push_back(make_pair(temp->str,temp->val));
            temp=temp->next;
        }
    }
};

bool comp(pair<string,int> a, pair<string,int> b){
    if(a.second!=b.second) return a.second>b.second;
    return a.first<b.first;
}
int main(){
    ofstream out;
    ifstream in;
    in.open("input.txt");
    out.open("output.txt");
    string str;
    ll l;
    while(in>>str){
        string abc="";
        for(long unsigned int i=0;i<str.size();i++)
            if(str[i]!='.'&&str[i]!=','&&str[i]!=':'&&str[i]!=';'&&str[i]!='!'&&str[i]!='?'){
                if(65<=int(str[i])&&int(str[i])<=90)
                    str[i]=char(int(str[i])+32);
                 abc+=str[i];
            }
        if(abc!=""){
            l.add(abc);
        }
    }
    l.ddd();
    sort(ans.begin(),ans.end(),comp);
    vector<pair<string,int> > :: iterator it;
    for(it=ans.begin();it!=ans.end();++it){
        out<<(*it).first<<" "<<(*it).second<<endl;
    }
    out.close();
    return 0;
}