#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int MAX_HW = 105;
//inputs
int H, W;
// int A[MAX_HW][MAX_HW];
// int B[MAX_HW][MAX_HW];

int main(){
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<vector<ll>> B(H, vector<ll>(W));
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            cin >> A[i][j];
        }
    }
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            cin >> B[i][j];
        }
    }

    ll ans = 0;
    for (int i=0;i<H-1;i++){
        for (int j=0;j<W-1;j++){
            ll d = (B[i][j] - A[i][j]);
            A[i][j] += d;
            A[i][j+1] += d;
            A[i+1][j] += d;
            A[i+1][j+1] += d;
            ans += abs(d);
        }
    }

    if (A == B){
        cout << "Yes" << endl;
        cout << ans << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
