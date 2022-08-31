#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> s;
    int n,cur=-1;
    s.insert(1);
    cin>>n;
    while(n-->0){
        cur = *s.begin();
        s.erase(s.begin());
        s.insert(cur*2);
        s.insert(cur*3);
        s.insert(cur*5);
    }
    cout<<cur<<endl;
    return 0;
}