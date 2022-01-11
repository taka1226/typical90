#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const int MAX_N = 100005;
const ll INF = 1e12;

//input
int N, Q;
ll X[MAX_N], Y[MAX_N];
int q;
ll new_X[MAX_N], new_Y[MAX_N];
int main(){
    cin >> N >> Q;
    for (int i=1;i<=N;i++){
        cin >> X[i] >> Y[i];
    }

    //new_X = X - Y, new_Y = X + Y
    for (int i=1;i<=N;i++){
        new_X[i] = X[i] - Y[i];
        new_Y[i] = X[i] + Y[i];
    }

    ll min_new_X = INF, min_new_Y = INF, max_new_X = -INF, max_new_Y = -INF;
    for (int i=1;i<=N;i++){
        min_new_X = min(min_new_X, new_X[i]);
        min_new_Y = min(min_new_Y, new_Y[i]);
        max_new_X = max(max_new_X, new_X[i]);
        max_new_Y = max(max_new_Y, new_Y[i]);
    }
    for (int i=0;i<Q;i++){
        cin >> q;
        ll v1 = abs(new_X[q] - min_new_X);
        ll v2 = abs(new_X[q] - max_new_X);
        ll v3 = abs(new_Y[q] - min_new_Y);
        ll v4 = abs(new_Y[q] - max_new_Y);

        cout << max({v1, v2, v3, v4}) << endl;
    }
    return 0;
}
