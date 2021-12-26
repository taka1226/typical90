#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const int MAX_N = 2005;
//input
int H, W;
ll A[MAX_N][MAX_N];

int main(){
    cin >> H >> W;
    for (int i=1;i<=H;i++){
        for (int j=1;j<=W;j++){
            cin >> A[i][j];
        }
    }

    ll S[MAX_N];
    for (int i=1;i<=H;i++){
        S[i] = 0;
        for (int j=1;j<=W;j++){
            S[i] += A[i][j];
        }
    }
    ll T[MAX_N];
    for (int i=1;i<=W;i++){
        T[i] = 0;
        for (int j=1;j<=H;j++){
            T[i] += A[j][i];
        }
    }

    for (int i=1;i<=H;i++){
        for (int j=1;j<=W;j++){
            cout << S[i] + T[j] - A[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}
