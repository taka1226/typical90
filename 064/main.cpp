#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int MAX_N = 100005;
//inputs
int N, Q;
ll A[MAX_N], B[MAX_N];
int L[MAX_N], R[MAX_N];
ll V[MAX_N];

int main(){
	cin >> N >> Q;
	for (int i=1;i<=N;i++){
		cin >> A[i];
	}
	for (int i=1;i<=Q;i++){
		cin >> L[i] >> R[i] >> V[i];
	}

	ll ans = 0;
	for (int i=1;i<=N-1;i++){
		B[i] = A[i+1] - A[i];
		ans += abs(B[i]);
	}

	for (int i=1;i<=Q;i++){
		ll mae = abs(B[L[i] - 1]) + abs(B[R[i]]);
		if (L[i] >= 2){
			B[L[i]-1] += V[i];
		}

		if (R[i] <= N - 1){
			B[R[i]] -= V[i];
		}

		ll ato = abs(B[L[i] - 1]) + abs(B[R[i]]);
		ans += (ato - mae);
		cout << ans << endl;

	}
	return 0;
}
