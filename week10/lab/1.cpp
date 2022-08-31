#include <iostream>
using namespace std;
#define NMAX 1000

struct vertex{
    vertex* next[26];
    bool isEndOfWorld;
    vertex(){
        isEndOfWorld=false;
        for(int i=0;i<26;i++) next[i]=NULL;
    }
};

struct Trie{
    vertex *root=new vertex();
    void insert(string s){
        int n=s.length();
        vertex * cur=root;
        for(int i=0;i<n;i++){
            if(cur->next[s[i]-'a']==NULL) cur->next[s[i]-'a']=new vertex();
            cur=cur->next[s[i]-'a'];
        }
        cur->isEndOfWorld=true;
    }
    bool search(string s){
        int n=s.length();
        vertex * cur=root;
        for(int i=0;i<n;i++){
            if(cur->next[s[i]-'a']==NULL) return false;
            cur=cur->next[s[i]-'a'];
        }
        return cur->isEndOfWorld;
    }
};
int main(){
    int n;
    cin>>n;
    string s;
    Trie t;
    for(int i=0;i<n;i++){
        cin>>s;
        t.insert(s);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>s;
        cout<<t.search(s)<<endl;
    }
    return 0;
}