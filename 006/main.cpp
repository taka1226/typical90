#include<bits/stdc++.h>
using namespace std;

//const
const int MAX_N = 100005;

//inputs
int N, K;
string S;

//i番目の右にある文字jのなかで最も左側にあるもののindex
int nex[MAX_N][26];

int main(){
    cin >> N >> K;
    cin >> S;

    // Step #2. 前計算
	for (int i = 0; i < 26; i++) nex[S.size()][i] = S.size();
	for (int i = (int)S.size() - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			if ((int)(S[i] - 'a') == j) {
				nex[i][j] = i;
			}
			else {
				nex[i][j] = nex[i + 1][j];
			}
		}
	}

    // for (int i=0;i<N;i++){
    //     for (int j=0;j<26;j++){
    //         cout << nex[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Step #3. 一文字ずつ貪欲に決める
	string Answer = "";
	int CurrentPos = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < 26; j++) {
			int NexPos = nex[CurrentPos][j];
			int MaxPossibleLength = (int)(S.size() - NexPos - 1) + i;
			if (MaxPossibleLength >= K) {
				Answer += (char)('a' + j);
				CurrentPos = NexPos + 1;
				break;
			}
		}
	}

	// Step #4. 出力
	cout << Answer << endl;
    return 0;
}
