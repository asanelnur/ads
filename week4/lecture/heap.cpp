#include <iostream>
#include <vector>
using namespace std;
class MinHeap{
    public:
    vector<int> a;

    int parent(int i){
        return (i-1)/2;
    }
    int right(int i){
        return 2*i+2;
    }
    int left(int i){
        return 2*i+1;
    }
    int getmin(){
        return a[0];
    }
    void sift_up(int i){
        while(i>0 && a[parent(i)>a[i]]){
            swap(a[parent(i)],a[i]);
            i=parent(i);
        }
    }
    void insert(int x){
        a.push_back(x);
        int i=a.size()-1;
        sift_up(i);
    }
    void heapify(int i){
        if(left(i)>a.size()-1){
            return;
        }
        int mp=left(i);
        if(right(i)<a.size() && a[mp]>a[right(i)]){
            mp=right(i);
        }
        if(a[mp]<a[i]){
            swap(a[mp],a[i]);
            heapify(mp);
        }
    }
    int extra_min(){
        int root_value=getmin();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size()>0){
            heapify(0);
        }
        return root_value;
    }
    void decrease_key(int i,int new_value){
        a[i]=new_value;
        sift_up(i);
    }
    void increase_key(int i,int new_value){
        a[i]=new_value;
        heapify(i);
    }
}
int main(){
    return 0;
}