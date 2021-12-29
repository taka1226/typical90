#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const
const int MAX_N = 100005;

//input
int N;
ll sum_1[MAX_N];
ll sum_2[MAX_N];
int Q;
int main(){
    cin >> N;
    for (int i=0;i<N;i++){
        int c, p;cin >> c >> p;
        if (c == 1){
            sum_1[i+1] = sum_1[i] + p;
            sum_2[i+1] = sum_2[i];
        }else if (c == 2){
            sum_1[i+1] = sum_1[i];
            sum_2[i+1] = sum_2[i] + p;
        }
    }
    cin >> Q;
    for (int i=0;i<Q;i++){
        int l, r;cin >> l >> r;
        cout << sum_1[r] - sum_1[l-1] << " " << sum_2[r] - sum_2[l-1] << endl;
    }
    return 0;
}
