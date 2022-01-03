#include<bits/stdc++.h>
using namespace std;
//const
const int MAX_H = 2005;
const int MAX_W = 2005;

const int WHITE = 0;
const int BLACK = 1;
//input
int H, W;
int M[MAX_H][MAX_W];
bool visited[MAX_H][MAX_W];
int Q;

void dfs(int ux, int uy, int gx, int gy){
    visited[ux][uy] = true;
    if (ux == gx && uy == gy){
        return;
    }
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i=0;i<4;i++){
        int vx = ux + dx[i];
        int vy = uy + dy[i];

        if (vx > 0 && vx <= H && vy > 0 && vy <= W && !visited[vx][vy] && M[vx][vy] == BLACK){
            dfs(vx, vy, gx, gy);
        }
    }
}

void debug_M(){
    for (int i=1;i<=H;i++){
        for (int j=1;j<=W;j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    cin >> H >> W;
    for (int i=1;i<=H;i++){
        for (int j=1;j<=W;j++){
            M[i][j] = WHITE;
            visited[i][j] = false;
        }
    }
    cin >> Q;
    for (int i=0;i<Q;i++){
        int t;cin >> t;
        if (t == 1){
            int r, c;cin >> r >> c;
            M[r][c] = BLACK;
        }else if (t == 2){
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            if (M[ra][ca] == WHITE || M[rb][cb] == WHITE){
                cout << "No" << endl;
            }else{
                for (int i=1;i<=H;i++){
                    for (int j=1;j<=W;j++){
                        visited[i][j] = false;
                    }
                }
                dfs(ra, ca, rb, cb);
                if (visited[rb][cb]){
                    cout << "Yes" << endl;
                }else{
                    cout << "No" << endl;
                }
            }
        }
    }
    return 0;
}
