#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const int MAX_W = 2 << 19;

//input
int n;
int W, N;
ll dat[MAX_W * 2 + 5];
ll lazy[MAX_W * 2 + 5];

void init(int n_){
    n = 1;
    while (n < n_) n *= 2;

    for (int i=0;i<n*2-1;i++){
        dat[i] = 0;
        lazy[i] = 0;
    }
}

void eval(int k, int l, int r){
    if (lazy[k] != 0){
        dat[k] = lazy[k];

        if (r - l > 1){
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] = lazy[k];
        }

        lazy[k] = 0;
    }
}

void update(int a, int b, ll x, int k, int l, int r){
    eval(k, l, r);

    if (b <= l || r <= a) return;

    if (a <= l && r <= b){
        lazy[k] = x;
        eval(k, l, r);
    }

    else{
        update(a, b, x, 2*k+1, l, (l+r)/2);
        update(a, b, x, 2*k+2, (l+r)/2, r);
        dat[k] = max(dat[2*k+1], dat[2*k+2]);
    }
}

ll query(int a, int b, int k, int l, int r){
    eval(k, l, r);
    if (b <= l || r <= a) return 0;
    if (a <= l && r <= b) return dat[k];
    ll v1 = query(a, b, 2*k+1, l, (l+r)/2);
    ll v2 = query(a, b, 2*k+2, (l+r)/2, r);

    return max(v1, v2);
}

int main(){
    cin >> W >> N;
    init(W);
    for (int i=0;i<N;i++){
        int x, y;cin >> x >> y;
        x--;
        ll height = query(x, y, 0, 0, n);
        height++;
        update(x, y, height, 0, 0, n);
        cout << height << endl;
    }

    return 0;
}
