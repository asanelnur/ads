#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    if(head==NULL){
        head=node;
        return head;
    }
    if(p==0){
        node->next=head;
        head=node;
        return head;
    }
    Node * item=head;
    int k=0;
    while(k<p-1){
        item=item->next;
        k++;
    }
    node->next=item->next;
    item->next=node;
    return head;
}
 
Node* remove(Node* head, int p){
    /* write your code here */
    Node * item=head;
    if(p==0){
        head=head->next;
        return head;
    }
    int k=0;
    while(k<p-1){
        item=item->next;
        k++;
    }
    item->next=item->next->next;
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    int k=0;
    int m=0;
    Node * item1=head;
    Node * item2=head;
    while(k<p1){
        item1=item1->next;
        k++;
    }
    while(m<p2){
        item2=item2->next;
        m++;
    }
    int cur=item1->val;
    item1->val=item2->val;
    item2->val=cur;
    return head;
}
 
Node* reverse(Node* head){
    /* write your code here */
    Node* ans=new Node(head->val);
    head=head->next;
    while(head!=NULL){
        Node* cur=new Node(head->val);
        ans->next=cur;
    }
    return ans;

}
 
void print(Node* head){
    /* write your code here */
    if(head==NULL) cout<<-1;
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
    while(x--){
        Node * item=head;
        Node * cur=head->next;
        while(item->next!=NULL){
            item=item->next;
        }
        item->next=head;
        head->next=NULL;
        head=cur;
    }
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    /* write your code here */
    while(x--){
        Node * item=head;
        while(item->next->next!=NULL){
            item=item->next;
        }
        Node * cur=item->next;
        item->next=NULL;
        cur->next=head;
        head=cur;
    }
    return head;
}
 
int main(){
    Node* head = NULL;
    while(1){
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; 
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}