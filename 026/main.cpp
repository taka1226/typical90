#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

int N;
vector<int> G[MAX_N];

int col[MAX_N];

void dfs(int u, int c){
    col[u] = c;
    for (auto v : G[u]){
        if (col[v] == -1){
            dfs(v, 1 - c);
        }
    }
}

int main(){
    cin >> N;
    for (int i=1;i<=N-1;i++){
        int a, b;cin >> a >> b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //col 配列の初期化
    for (int i=0;i<N;i++){
        col[i] = -1;
    }

    dfs(0, 0);

    int cnt_0 = 0;
    int cnt_1 = 0;
    for (int i=0;i<N;i++){
        if (col[i] == 0) cnt_0++;
    }

    int ans_c;
    if (cnt_0 >= N / 2) ans_c = 0;
    else ans_c = 1;

    int cnt = 0;
    for (int i=0;i<N;i++){
        if (cnt == N/2) break;
        if (col[i] == ans_c){
            cout << i + 1 << " ";
            cnt++;
        }
    }
    cout << endl;


    return 0;
}
