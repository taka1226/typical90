#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int MAX_N = 200005;

//inputs
int N, Q;
ll A[MAX_N];

int main(){
	cin >> N >> Q;
	for (int i=0;i<N;i++){
		cin >> A[i];
	}
	int shift = 0;
	while (Q--){
		int t, x, y;
		cin >> t >> x >> y;x--;y--;
		if (t == 1){
			swap(A[(x - shift + N) % N], A[(y - shift + N) % N]);
		}
		if (t == 2){
			shift++;
		}
		if (t == 3){
			cout << A[(x - shift + N) % N] << endl;
		}
	}
	return 0;
}
