#include<bits/stdc++.h>
using namespace std;
//cosnt
const int MAX_N = 15;
//inputs
int N;
int A[MAX_N][MAX_N];
int M;
bool kenaku[MAX_N][MAX_N];

int main(){
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }
    vector<int> V;
    for (int i=0;i<N;i++){
        V.push_back(i);
    }
    cin >> M;
    for (int i=0;i<M;i++){
        int x, y;
        cin >> x >> y;x--;y--;
        kenaku[x][y] = true;
        kenaku[y][x] = true;
    }

    //next permutation
    //ソートしないと機能しない
    int ans = INT_MAX;
    sort(V.begin(),V.end());  //必ずソートしてから使うように！
    do{
        vector<int> v(N);
        for (int i=0;i<N;i++){
            int c = V[i];
            v[c] = i;
        }
        bool flg = true;
        for (int i=0;i<N-1;i++){
            if (kenaku[v[i]][v[i+1]]){
                flg = false;
            }
        }
        if (!flg) continue;
        int res = 0;
        for (int i=0;i<N;i++){
            res += A[i][V[i]];
        }
        ans = min(ans, res);

    }while(next_permutation(V.begin(),V.end()));

    if (ans == INT_MAX){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}
