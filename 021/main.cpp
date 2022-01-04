#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const int MAX_N = 100005;
//input
int N, M;
vector<int>G[MAX_N];
vector<int>rG[MAX_N];

vector<int> new_G;
bool visited[MAX_N];

void dfs(int u){
    visited[u] = true;
    for (auto v : G[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
    new_G.push_back(u);
}

ll dfs2(int u){
    ll ans = 1;
    visited[u] = true;
    for (auto v : rG[u]){
        if (!visited[v]){
            ans += dfs2(v);
        }
    }
    return ans;
}
int main(){
    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a, b;cin >> a >> b;
        G[a].push_back(b);
        rG[b].push_back(a);
    }

    while(1){
        int start = -1;
        for (int i=1;i<=N;i++){
            if (!visited[i]){
                start = i;
                break;
            }
        }
        if (start == -1) break;
        dfs(start);
    }

    reverse(new_G.begin(), new_G.end());
    for (int i=1;i<=N;i++){
        visited[i] = false;
    }

    ll ans = 0;
    for (int i=0;i<new_G.size();i++){
        int u = new_G[i];
        if (visited[u])continue;
        ll res = dfs2(u);
        ans += res * (res-1) / 2;
    }

    cout << ans << endl;

    return 0;
}
