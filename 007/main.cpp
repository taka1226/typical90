#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const ll MAX_N = 300005;
const ll INF = 1e13;
//input
ll N, Q;

int main(){
    cin >> N;
    set<ll> A;
    for (ll i=0;i<N;i++){
        ll a;
        cin >> a;
        A.insert(a);
    }
    cin >> Q;
    vector<ll> B(Q);
    for (ll i=0;i<Q;i++){
        cin >> B[i];
    }

    for (ll i=0;i<Q;i++){
        auto iter = A.lower_bound(B[i]);
        if (iter == A.begin()){
            cout << abs(*iter - B[i]) << endl;
        }else if (iter == A.end()){
            iter--;
            cout << abs(*iter - B[i]) << endl;
        }else{
            ll diff1 = abs(*iter - B[i]);
            iter--;
            ll diff2 = abs(*iter - B[i]);
            cout << min(diff1, diff2) << endl;
        }

    }


    return 0;
}
