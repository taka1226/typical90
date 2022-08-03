#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 105;

//inputs
int N, S;
int A[MAX_N], B[MAX_N];
bool dp[MAX_N][100005];


int main(){
	cin >> N >> S;
	for (int i=1;i<=N;i++){
		cin >> A[i] >> B[i];
	}

	dp[0][0] = true;
	for (int i=1;i<=N;i++){
		for (int j=0;j<=S;j++){
			if (j - A[i] >= 0){
				dp[i][j] = (dp[i-1][j-A[i]] || dp[i][j]);
			}
			if (j - B[i] >= 0){
				dp[i][j] = (dp[i-1][j-B[i]] || dp[i][j]);
			}
		}
	}

	if (!dp[N][S]){
		cout << "Impossible" << endl;
	}else{
		string res(N, '?');
		int pos = S;
		for (int i=N;i>=1;i--){
			if (pos >= B[i] && dp[i-1][pos - B[i]]){
				res[i-1] = 'B';
				pos -= B[i];
			}else{
				res[i-1] = 'A';
				pos -= A[i];
			}
		}
		cout << res << endl;
	}

	return 0;
}
