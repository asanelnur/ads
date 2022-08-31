#include <iostream>
using namespace std;
#define NMAX 100000

struct vertex{
    int next[26];
    bool isEndOfWorld;
    int cnt;
    vertex(){
        cnt=0;
    }
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
    for(int i=s.length()-1;i>=0;i--){
        int c=s[i]-'a';
        if(t[v].next[c]==-1){
            for(int j=0;j<26;j++){
                t[sz].next[j]=-1;
            }
            t[v].next[c]=sz++;
        }
        v=t[v].next[c];
        t[v].cnt++;
    }
    t[v].isEndOfWorld=true;
}

int EndWith(string s){
    int v=0;
    for(int i=s.length()-1;i>=0;i--){
        int c=s[i]-'a';
        //t[v]--->s[i]
        if(t[v].next[c]==-1){
            return false;
        }
        v=t[v].next[c];
    }
    return t[v].cnt;
}
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    init();
    for(int i=0;i<n;i++){
        cin>>s;
        add_string(s);
    }
    for(int i=0;i<m;i++){
        cin>>s;
        cout<<EndWith(s)<<endl;
    }
    return 0;
}