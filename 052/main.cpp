#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
//const
const int MAX_N = 105;
const ll mod = 1000000007;
//inputs
int N;
ll A[MAX_N][6];

int main(){
	cin >> N;
	for (int i=1;i<=N;i++){
		for (int j=0;j<6;j++){
			cin >> A[i][j];
		}
	}

	ll ans[MAX_N];
	ans[0] = 1;
	for (int i=1;i<=N;i++){
		ll res = 0;
		for (int j=0;j<6;j++){
			res += A[i][j] * ans[i-1];
			res %= mod;
		}
		ans[i] = res % mod;
	}

	cout << ans[N] % mod << endl;
	return 0;
}
