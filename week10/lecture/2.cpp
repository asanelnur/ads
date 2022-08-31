#include <iostream>
using namespace std;
#define NMAX 1000

struct vertex{
    int next[26];
    bool isEndOfWorld;
};

vertex t[NMAX+1];
int sz=1;

void init(){
    for(int j=0;j<26;j++){
        t[0].next[j]=-1;
    }
}
void add_string(string s){
    int v=0;
    for(int i=0;i<s.length();i++){
        int c=s[i]-'a';
        //t[v]--->s[i]
        if(t[v].next[c]==-1){
            for(int j=0;j<26;j++){
                t[sz].next[j]=-1;
            }
            t[v].next[c]=sz++;
        }
        v=t[v].next[c];
    }
    t[v].isEndOfWorld=true;
}
int main(){
    int n;
    cin>>n;
    string s;
    init();
    for(int i=0;i<n;i++){
        cin>>s;
        add_string(s);
    }
    // int m;
    // cin>>m;
    for(int i=0;i<sz;i++){
        for(int j=0;j<26;j++){
            cout<<t[i].next[j]<<" ";
        }
        cout<<t[i].isEndOfWorld;
        cout<<endl;
    }
    return 0;
}