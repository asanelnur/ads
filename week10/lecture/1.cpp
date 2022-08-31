/*
Trie(Tree)
Что такое бор?

     ( ) -root
( )a       ( )b     "","a","b","bx"
        ( )x

struct v{
    int next[k];
    bool leaf;
}


 hello,helloworld,hi,helios
                                   (#)
                                (h)
                            (i)    (e)
                                      (l)
                                   (i)  (l)
                                  (o)     (o)
                                (s)         (w)
                                             (o)
                                               (r)
                                                 (l)
                                                   (d)
*/

#include <iostream>
using namespace std;
#define NMAX 1000

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
        t[v].cnt++;
    }
    t[v].isEndOfWorld=true;
}

bool search(string s){
    int v=0;
    for(int i=0;i<s.length();i++){
        int c=s[i]-'a';
        //t[v]--->s[i]
        if(t[v].next[c]==-1){
            return false;
        }
        v=t[v].next[c];
    }
    return t[v].isEndOfWorld;
}
bool startsWith(string s){
    int v=0;
    int cn=0;
    for(int i=0;i<s.length();i++){
        int c=s[i]-'a';
        //t[v]--->s[i]
        if(t[v].next[c]==-1){
            break;
        }
        v=t[v].next[c];
    }
    //cout<<cn<<" "<<s.length()<<" ";
    if(s.length()==cn){
        return true;
    }
    return false;
}

int find2(string s){
    int v=0;
    for(int i=0;i<s.length();i++){
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
    int n;
    cin>>n;
    string s;
    init();
    for(int i=0;i<n;i++){
        cin>>s;
        add_string(s);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>s;
        cout<<find2(s)<<endl;
    }
    return 0;
}