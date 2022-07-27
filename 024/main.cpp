#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
//inputs
int N, K;
int A[MAX_N], B[MAX_N];

int main(){
	cin >> N >> K;
	for (int i=0;i<N;i++){
		cin >> A[i];
	}
	for (int i=0;i<N;i++){
		cin >> B[i];
	}

	int diff = 0;
	for (int i=0;i<N;i++){
		diff += abs(A[i] - B[i]);
	}

	if (K < diff){
		cout << "No" << endl;
	}else{
		if ((K - diff) % 2 == 0){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}
