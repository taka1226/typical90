#include<bits/stdc++.h>
using namespace std;
//const
const int MAX_N = 100005;
const int INF = 1e6;
//input
int N;
vector<int> V[MAX_N];
int main(){
    cin >> N;
    for (int i=0;i<N-1;i++){
        int a, b;cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    //1から始める
    int d[MAX_N];
    queue<int> que;
    bool visited[MAX_N];
    que.push(1);
    for (int i=1;i<=N;i++){
        d[i] = INF;
        visited[i] = false;
    }
    d[1] = 0;
    visited[1] = true;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for (auto& v : V[u]){
            if (!visited[v]){
                visited[v] = true;
                d[v] = min(d[v], d[u] + 1);
                que.push(v);
            }
        }
    }

    int start = 0;
    int max_len = 0;
    for (int i=1;i<=N;i++){
        if (d[i] > max_len){
            start = i;
            max_len = d[i];
        }
    }

    //1から始める
    queue<int> que2;
    que2.push(start);
    for (int i=1;i<=N;i++){
        d[i] = INF;
        visited[i] = false;
    }
    d[start] = 0;
    visited[start] = true;
    while(!que2.empty()){
        int u = que2.front();
        que2.pop();
        for (auto& v : V[u]){
            if (!visited[v]){
                visited[v] = true;
                d[v] = min(d[v], d[u] + 1);
                que2.push(v);
            }
        }
    }

    max_len = 0;
    for (int i=1;i<=N;i++){
        if (d[i] > max_len){
            max_len = d[i];
        }
    }

    cout << max_len + 1 << endl;
    return 0;
}
