#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const int MAX_N = 1e5 + 5;
//input
int N;
vector<int>G[MAX_N];
int dp[MAX_N]; //頂点i の直属の部下
int A[MAX_N], B[MAX_N];

void dfs(int u, int pre){
    dp[u] = 1;
    for (auto& v : G[u]){
        if (v != pre){
            dfs(v, u);
            dp[u] += dp[v];
        }
    }
    return;
}
int main(){
    cin >> N;
    for (int i=0;i<N-1;i++){
        int a, b; cin >> a >> b;
        A[i] = a;B[i] = b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, -1);

    ll ans = 0;
    for (int i=0;i<N-1;i++){
        ll r = min(dp[A[i]], dp[B[i]]);
        ans += r * (N - r);
    }

    cout << ans << endl;
    return 0;
}
