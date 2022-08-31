#include <bits/stdc++.h>
using namespace std;
 
struct Node {
  int value;
  int ans;
  Node *prev;
  Node(int x) {
    value = x;
    prev = NULL;
    ans = -1;
  }
};
 
struct Stack {
  private:
    Node * head;
    int sz;
  public:
    Stack(){
        head=NULL;
        sz=0;
    }
    int top() { 
      return head->value; 
    }
   
    void pop() {
      head = head->prev;
      sz--;
    }
 
    int size() { 
      return sz;
    }
 
    bool empty() { 
      return sz == 0; 
    }
 
    int push(int x) {
        sz++;
        Node * node = new Node(x);
        if(head==NULL) head=node;
        else{
            node->prev=head;
            Node * temp=head;
            while(temp!=NULL){
                if(node->value >= temp->value ){node->ans=temp->value;break;}
                temp=temp->prev;
            }
            head=node;
        }
        return node->ans;         
    }
 
}st;
 
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    cout << st.push(x) << " ";
  }
  return 0;
}