#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
//const
const int MAX_N = 45;
//inputs
ll P;
int N, K;
ll A[MAX_N][MAX_N];
ll d[MAX_N][MAX_N];

ll warshall_floyd(ll x) {
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (A[i][j] == -1){
				d[i][j] = x;
			}else{
				d[i][j] = A[i][j];
			}
		}
	}
	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	ll res = 0;
	for (int i=0;i<N;i++){
		for (int j=i+1;j<N;j++){
			if (d[i][j] <= P) res++;
		}
	}
	return res;
}

int main(){
	cin >> N >> P >> K;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			cin >> A[i][j];
		}
	}

	ll lh = 0LL;
	ll rh = 100000000000LL;
	ll mid;
	for (int i=0;i<100;i++){
		mid = (lh + rh) / 2LL;
		if (warshall_floyd(mid) <= K){
			rh = mid;
		}else if (warshall_floyd(mid) > K){
			lh = mid;
		}
	}
	ll ans1 = mid;
	lh = 0LL;
	rh = 100000000000LL;
	for (int i=0;i<100;i++){
		mid = (lh + rh) / 2LL;
		if (warshall_floyd(mid) < K){
			rh = mid;
		}else if (warshall_floyd(mid) >= K){
			lh = mid;
		}
	}
	ll ans2 = mid;

	if (ans2 - ans1 >= 1000000000LL){
		cout << "Infinity" << endl;
	}else{
		cout << ans2 - ans1 << endl;
	}
	return 0;
}
