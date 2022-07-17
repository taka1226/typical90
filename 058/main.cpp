#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int mod = 100000;

int digit_sum(int n){
	int res = 0;
	while (n > 0){
		res += (n % 10);
		n /= 10;
	}
	return res;
}

//inputs
int N;
ll K;

int main(){
	cin >> N >> K;
	vector<int> nxt(mod);
	for (int i=0;i<mod;i++){
		nxt[i] = (i + digit_sum(i)) % mod;
	}

	vector<int> time_stamp(mod, -1);
	int pos = N, cnt = 0;
	while (time_stamp[pos] == -1){
		time_stamp[pos] = cnt;
		pos = nxt[pos];
		cnt++;
	}
	int cycle = cnt - time_stamp[pos];
	if (K >= time_stamp[pos]){
		K = (K - time_stamp[pos]) % cycle + time_stamp[pos];
	}
	int ans = -1;
	for (int i=0;i<mod;i++){
		if (time_stamp[i] == K){
			ans = i;
		}
	}

	cout << ans << endl;
	return 0;
}
