#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e7 + 5;
int N;int K;
int cnt[MAX_N];
int main(){
    cin >> N >> K;

    for (int i=0;i<=N;i++){
        cnt[i] = 0;
    }
    for (int i=2;i<=N;i++){
        if (cnt[i] >= 1) continue;
        for (int j=i;j<=N;j+=i)cnt[j] += 1;
    }

    int ans = 0;
    for (int i=2;i<=N;i++){
        if (cnt[i] >= K) ans += 1;
    }

    cout << ans << endl;
    return 0;
}
