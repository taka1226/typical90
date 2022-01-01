#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//input
int N;
int main(){
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);

    for (int i=0;i<N;i++){
        cin >> A[i];
    }
    for (int i=0;i<N;i++){
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll ans = 0;
    for (int i=0;i<N;i++){
        ans += abs(A[i] - B[i]);
    }

    cout << ans << endl;
    return 0;
}
