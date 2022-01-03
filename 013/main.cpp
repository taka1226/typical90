#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const int MAX_N = 100005;
//input
int N, M;
vector<pair<int, ll>> G[MAX_N];
ll dist[MAX_N];
ll dist1[MAX_N];
ll distN[MAX_N];

void dijkstra(int start){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    for (int i=1;i<=N;i++){
        dist[i] = (1LL << 60);
    }
    dist[start] = 0;
    Q.push(make_pair(0, start));
    while (!Q.empty()){
        int u = Q.top().second;Q.pop();
        for (int i=0;i<G[u].size();i++){
            int v = G[u][i].first;
            ll cost = G[u][i].second;
            if (dist[v] > dist[u] + cost){
                dist[v] = dist[u] + cost;
                Q.push(make_pair(dist[v], v));
            }
        }
    }

}
int main(){
    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a, b;ll c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    dijkstra(1);
    for (int i=1;i<=N;i++){
        dist1[i] = dist[i];
    }

    dijkstra(N);
    for (int i=1;i<=N;i++){
        distN[i] = dist[i];
    }

    for (int i=1;i<=N;i++){
        cout << dist1[i] + distN[i] << endl;
    }

    return 0;
}
