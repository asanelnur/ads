#include <iostream>
using namespace std;
struct node{
    int val;
    node * right;
    node * left;
    node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
struct bst{
    private:
    node * _root;
    int cnt_numbers;
    node * add(node * current,int x){
        if(current==NULL) return new node(x);
        if(x < current->val){
            current->left=add(current->left,x);
        }
        if(x>current->val){
            current->right=add(current->right,x);
        }
        return current;
    }
    bool find(node * current,int x){
        if(current==NULL) return false;
        if(current->val==x) return true;
        if(x<current->val) return find(current->left,x);
        return find(current->right,x);
    }
    int right_most(node * current){
        if(current==NULL) return -1;
        if(current->right==NULL) return current->val;
        return right_most(current->right);
    }
    int sec_max(node * current){
        if(current->right==NULL && current->left!=NULL){
            return right_most(current->left);
        }
        if(current->right != NULL && current->right->left==NULL && current->right->right==NULL){
            return current->val;
        }
        return sec_max(current->right);
    }
    public:
    bst(){
        _root=NULL;
        cnt_numbers=0;
    }
    void add(int x){
        if(find(_root,x)==false){
            cnt_numbers++;
            node * res=add(_root,x);
            if(_root==NULL){
                _root=res;
             }
        }
    }
    void find_second_max_number(){
        cout<<sec_max(_root);
    }
};
int main(){
    bst * tree=new bst();
    int x;
    while(1){
        cin>>x;
        if(x==0) break;
        tree->add(x);
    }
    tree->find_second_max_number();
    return 0;
}