#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> st;
    st.push(5);
    st.push(12);
    st.push(17);
    cout<<st.top()<<" "<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    return 0;
}