#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//input
ll A, B, C, N;
vector<ll> S(3);
int main(){
    cin >> N;
    cin >> A >> B >> C;
    S[0] = A;S[1] = B;S[2] = C;

    //sort
    sort(S.begin(), S.end(), greater<ll>());

    ll min_cnt = 1e18;
    for (ll i=0;i<10000;i++){
        for (ll j=0;j<10000;j++){
            ll left = N - (S[0] * i + S[1] * j);
            if (left >= 0 && left % S[2] == 0){
                ll cand = i + j + left / S[2];
                if (min_cnt > cand){
                    min_cnt = cand;
                }
            }
        }
    }

    cout << min_cnt << endl;

    return 0;
}
