#include <iostream>
#include <vector>
using namespace std;
long long saveAns;
vector<int> array;
int n, k;
void binarysearch(long long l, long long r){
	if(r < l) return;
	long long mid = l + r >> 1;
	long long sum = 0;
	int cntcur = 1;
	for(int i = 0; i < n; ++i){
		sum += array[i];
		if(sum > mid){
			sum = array[i];
			cntcur++;
		}
	}	
	if(cntcur <= k){
		saveAns = mid;
		binarysearch(l, mid - 1);
	}else{
		binarysearch(mid + 1, r);
	}
}
int main(){
	cin >> n >> k;
	array.resize(n);
	int mx = 0;
	for(int i = 0; i < n; ++i){
		cin >> array[i];
		mx = max(mx, array[i]);
	}
	binarysearch(mx, 1e18);
	cout << saveAns << endl;
	return 0;
}