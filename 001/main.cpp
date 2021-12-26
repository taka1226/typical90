#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const int MAX_N = 100005;
//input
int N, K;
ll L;

//xcm のピースを K+1 個以上作れるかどうか
bool C(ll x, vector<ll> a){
    ll s = 0;
    ll cnt = 0;
    while (1){
        int next_i = lower_bound(a.begin(), a.end(), x + s) - a.begin();
        if (next_i == N + 1)break;
        cnt++;
        s = a[next_i];
    }
    return cnt >= K+1;
}
int main(){
    cin >> N >> L;
    cin >> K;
    vector<ll> A(N+1);
    for (int i=0;i<N;i++){
        cin >> A[i];
    }
    A[N] = L;

    ll lb = 0;
    ll rb = 1e10;
    ll mid;
    for (int i=0;i<200;i++){
        mid = (lb + rb) / 2;
        if (C(mid, A)){
            lb = mid;
        }else{
            rb = mid;
        }

    }
    cout << mid << endl;


    return 0;
}
