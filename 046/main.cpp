#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int MAX_N = 100005;

//inputs
int N;
int A[MAX_N], B[MAX_N], C[MAX_N];
map<int, int> ra, rb, rc;

int main(){
	cin >> N;
	for (int i=0;i<N;i++){
		cin >> A[i];
	}
	for (int i=0;i<N;i++){
		cin >> B[i];
	}
	for (int i=0;i<N;i++){
		cin >> C[i];
	}

	for (int i=0;i<N;i++){
		ra[A[i] % 46]++;
		rb[B[i] % 46]++;
		rc[C[i] % 46]++;
	}

	ll ans = 0;
	for (int i=0;i<46;i++){
		for (int j=0;j<46;j++){
			for (int k=0;k<46;k++){
				if (i + j + k % 46 == 0){
					ans += (ra[i] * rb[j] * rc[k]);
				}
			}
		}
	}

	cout << ans << endl;


	return 0;
}
