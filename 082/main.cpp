#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;


//const
const ll mod = 1000000007;

//inputs
ll L, R;
ll power10[22];

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

ll div(ll a, ll b, ll mod){
    return (a * mod_pow(b, mod - 2, mod)) % mod;
}

//1 + 2 + ... + X % mod
ll f(ll X){
    ll v1 = X % mod;
    ll v2 = (X + 1) % mod;
    ll v = (v1 * v2) % mod;
    return div(v, 2, mod);
}

void init(){
    power10[0] = 1;
    for (int i=1;i<=19;i++){
        power10[i] = (10ULL * power10[i-1]);
    }
}

int main(){
    init();
    cin >> L >> R;

    ll ans = 0;
    for (int i=1;i<=19;i++){
        ll vl = max(L, power10[i-1]);
        ll vr = min(R, power10[i] - 1ULL);
        if (vl > vr) continue;
        ll val = (f(vr) - f(vl - 1) + mod) % mod;
        ans += 1LL * i * val;
        ans %= mod;
    }



    cout << ans << endl;
    return 0;
}
