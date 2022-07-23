#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int MAX_N = 300005;

int N;

int main(){
    cin >> N;
    vector<ll> A(N, 0LL);
    for (int i=0;i<N;i++){
        cin >> A[i];
    }
    vector<ll> rA = A;
    reverse(rA.begin(), rA.end());
    vector<ll> dp(N+1, LLONG_MAX);
    vector<ll> rdp(N+1, LLONG_MAX);

    int P[MAX_N];
    int Q[MAX_N];

    for (int i=0;i<N;i++){
        int index = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[index] = A[i];
        P[i] = index + 1;
    }

    for (int i=0;i<N;i++){
        int index = lower_bound(rdp.begin(), rdp.end(), rA[i]) - rdp.begin();
        rdp[index] = rA[i];
        Q[N - i - 1] = index + 1;
    }

    int ans = -1;
    for (int i=0;i<N;i++){
        ans = max(ans, P[i] + Q[i] - 1);
    }

    cout << ans << endl;


    return 0;
}
