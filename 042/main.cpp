#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int MAX_N = 100005;
const ll mod = 1000000007;

//inputs
int K;

ll dp[MAX_N];

int main(){
	cin >> K;
	for (int i=0;i<MAX_N;i++){
		dp[i] = 0LL;
	}
	if (K % 9 != 0){
		cout << 0 << endl;
	}else{
		dp[0] = 1LL;
		for (int i=1;i<=K;i++){
			int B = min(i, 9);
			for (int j=1;j<=B;j++){
				dp[i] += dp[i-j];
				dp[i] %= mod;
			}
		}
		cout << dp[K]  % mod << endl;
	}
	return 0;
}
