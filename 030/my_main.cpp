#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const int MAX_N = 1e7 + 5;
//input
ll N;int K;
bool is_prime[MAX_N + 1]; // is_prime[i]がtrueならば iは素数
int cnt[MAX_N];

//n以下の素数の数を返す
void sieve(int n){
    //ll ans = 0;
    for (int i=0;i<=n;i++){
        is_prime[i] = true;
        cnt[i] = 0;
    }
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i=2;i<=n;i++){
        if (is_prime[i]){
            cnt[i]++;
            for (int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
                cnt[j]++;
            }
        }
    }
    return;
}

int main(){
    cin >> N >> K;
    sieve(N);

    ll ans = 0;
    for (int i=2;i<=N;i++){
        if (cnt[i] >= K)ans++;
    }

    cout << ans << endl;
    return 0;
}
