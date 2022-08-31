#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
int main(){
    set<int> a,b;
    size_t n;
    cin >> n;
    copy_n(istream_iterator<int>(cin),n,inserter(a,a.end()));
    cin >> n;
    copy_n(istream_iterator<int>(cin),n,inserter(b,b.end()));
    cout << ((a==b)? "YES" : "NO") << endl;
}