#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

//inputs
ll N, M;
ll P;

ll mod_pow(ll a, ll p, ll mod){
    ll res = 1;
    while (p > 0){
        if (p & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}

int main(){
    cin >> N >> M >> P;

    cout << mod_pow(N, P, M) << endl;

}
