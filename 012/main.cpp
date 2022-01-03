#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;
//const
const int MAX_H = 2005;
const int MAX_W = 2005;

const int WHITE = 0;
const int RED = 1;

//input
int H, W;
int Q;
int M[MAX_H][MAX_W];

void query1(int r, int c, dsu* d){
    M[r][c] = RED;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    for (int i=0;i<4;i++){
        int new_r = r + dx[i];
        int new_c = c + dy[i];

        int hash1 = r * W + c;
        int hash2 = new_r * W + new_c;

        if (M[new_r][new_c] == RED && hash2 > W && hash2 <= (H+1) * W){
            d->merge(hash1, hash2);
        }
    }

    return;
}

void query2(int ra, int ca, int rb, int cb, dsu* d){
    if (M[ra][ca] == WHITE || M[rb][cb] == WHITE){
        cout << "No" << endl;
    }else{
        int hash1 = ra * W + ca;
        int hash2 = rb * W + cb;
        // cout << hash1 << " " << hash2 <<  d.same(hash1, hash2) << " " << endl;
        if (d->same(hash1, hash2)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return;
}

int main(){
    cin >> H >> W;
    for (int i=1;i<=H;i++){
        for (int j=1;j<=W;j++){
            M[i][j] = WHITE;
        }
    }

    dsu d(H * W + W + 1);
    cin >> Q;
    for (int i=0;i<Q;i++){
        int t;cin >> t;
        if (t == 1){
            int r, c;cin >> r >> c;
            query1(r, c, &d);
        }else if (t == 2){
            int ra, ca, rb, cb;cin >> ra >> ca >> rb >> cb;
            query2(ra, ca, rb, cb, &d);
        }
    }
    return 0;
}
