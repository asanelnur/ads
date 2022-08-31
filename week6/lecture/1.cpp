// online-текст меняется во время работы        offline- текст не будет меняеться

//на самом деле: text -> string 
//pattern ->string 

//hash (преобразовать обьекта) -> f(a1,a2,...,an)-> b1,b2,b3 
// хороший функция - аутпут меньше чем инпут и если инпуты уникальные тогда инпуты тоже должны быть уникальными.

/*
Robin Kard
f(s)->int 

A-65 
B-66 это тоже хеш функия 


s1='AB'->X:int->65+66=131
s2='BA'-> 66+55=131 it isn't correct

f(s)-> g(i,ASCI(s_i))
f(s)-> g(i,s_i-'A')

f(s)->g(i,j)
0 .... 26   (27)      (31) в некоторыч литературах (1111111);
29^i->j

h(s)=S0*p^0+S1*p^1+S2*p^2+S3*p^3+...


(i,j)->(31^i,j)-> s.length --- i=0: Si*31^i   => 'AB'!="BA"

hash(s)= s.length ---- i=0: ((Si*p^i)%q)%q      [o ... q]
*/

#include <iostream>
using namespace std;
int h(string str){
    long long p=1;
    int q=1e+9+7;
    long long s=0;
    for(int i=0;i<str.length();i++){
        s=(s+(str[i]-'a'+1)*p)%q;
        p=(p*31)%q;
    }
    return s;
}
int main(){
    string str;
    cin>>str;
    cout<<h(str);
    return 0;
}