#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;
//const
const int MAX_H = 2005;
const int MAX_W = 2005;

//inputs
int H, W, Q;
bool used[MAX_H][MAX_W];

dsu d(MAX_H * MAX_W);

void query1(int r, int c){
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int i=0;i<4;i++){
        int sx = r + dx[i];
        int sy = c + dy[i];
        if (!used[sx][sy]) continue;
        int hash1 = (r - 1) * W + (c - 1);
        int hash2 = (sx - 1) * W + (sy - 1);
        d.merge(hash1, hash2);
    }
    used[r][c] = true;
}

bool query2(int ra, int ca, int rb, int cb){
    if (!used[ra][ca] || !used[rb][cb]) return false;

    int hash1 = (ra - 1) * W + (ca - 1);
    int hash2 = (rb - 1) * W + (cb - 1);
    if (d.same(hash1, hash2)) return true;

    return false;
}

int main(){
    cin >> H >> W;
    cin >> Q;
    for (int i=0;i<Q;i++){
        int q;cin >> q;
        if (q == 1){
            int r, c;cin >> r >> c;
            query1(r, c);
        }else if (q == 2){
            int ra, ca, rb, cb;cin >> ra >> ca >> rb >> cb;
            bool flg = query2(ra, ca, rb, cb);
            if (flg){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }

    return 0;
}
