#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

//cosnt
const int MAX_N = 100005;

//inputs
int N, K;
int A[MAX_N];
map<int, int> mp;

int main(){
    cin >> N >> K;
    for (int i=0;i<N;i++){
        cin >> A[i];
    }

    int r = 0;
    int ans = -1;
    int cnt = 0;
    for (int l=0;l<N;l++){
        while (r < N){
            if (mp[A[r]] == 0 && cnt == K) break;
            if (mp[A[r]] == 0) cnt++;
            mp[A[r]] += 1;
            r++;
        }

        if (l == r) continue;

        ans = max(ans, r - l);

        if (mp[A[l]] == 1) cnt--;
        mp[A[l]] -= 1;
    }

    cout << ans << endl;
    return 0;
}
