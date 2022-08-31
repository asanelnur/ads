/*
   Префикс функция - тоже самое хеш, какой-то своиства который 
позваляет нам делать сравнение и поиск быстрее.

   Prefix   s.substring(0,k)  , k(- [1,|s|]
example: abcda -> a,ab,abc,abcd,abcda     
suffix-это часть строки на который закачивается страка s.substring(i,|s|-i)  i(-[0,|s|-1]
example: abcda-> a,da,cda,bcda,abcda
prefix-function 
P[0...n-1]  

S-> [0   0,1    0,1,2    0,1,2,3    0,1,2,3,4    ....]
i--->suffix : t=s.sustr(0,i);    
p1   s1
p2   s2
p3   s3
и ишем кто совпал по значению, если совпали наиболшее длину совпадения 
мы пишем в качестве p[i];

example:
s=abcabcd    |s|=7
     0   1     2      3      4        5        6
1) ["a","ab","abc","abca","abcab","abcabc","abcabcd"]
P[0...6]
2)P[0]=0;  P[1]=0;  P[2]=0;   P[3]=1   P[4]=2 (ab=ab);   P[5]=3 (abc=abc);   P[6]=0
3)[0,0,0,1,2,3,0]
*/

#include <iostream>
#include <vector>
using namespace std;
int f(string t){
    //cout<<t<<endl;
    vector<string> pr;
    vector<string> sf;
    for(int i=0;i<t.size()-1;i++){
        pr.push_back(t.substr(0,i+1));
    }
    for(int i=0;i<t.size()-1;i++){
        sf.push_back(t.substr(t.size()-1-i,i+1));
    }
    for(int i=t.size()-2;i>=0;--i){
        if(pr[i]==sf[i]){
            return pr[i].size();
        }
    }
    return 0;
}
int main(){
    string s;
    cin>>s;

    int p[s.size()];
    for(int i=0;i<s.size();i++){
        //cout<<s.substr(0,i+1)<<endl;
        p[i]=f(s.substr(0,i+1));
    }
    for(int i=0;i<s.size();i++){
        cout<<p[i]<<" ";
    }
    return 0;
}