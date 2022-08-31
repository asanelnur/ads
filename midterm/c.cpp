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
    Node * tail;
    int sz;
  public:
    Stack(){
        tail=NULL;
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
        if(head==NULL) head=tail=node;
        else{
            node->prev=tail;
            Node * temp=tail;
            while(temp!=NULL){
                if(node->value >= temp->value ){node->ans=temp->value;break;}
                temp=temp->prev;
            }
            tail=node;
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