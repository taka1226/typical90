#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const int MAX_N = 100005;

//input
int N;
string S;

ll dp[MAX_N][8];
int main(){
    cin >> N;
    cin >> S;

    string T = "atcoder";
    for (int i=0;i<=N;i++){
        dp[i][0] = 1;
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=7;j++){
            if (S[i-1] == T[j-1]){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % (ll)(1e9 + 7);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    cout << dp[N][7] << endl;


    return 0;
}
