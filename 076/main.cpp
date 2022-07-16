#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

//const
const int MAX_N = 100005;
//inputs
int N;
ll A[MAX_N];

ll B[MAX_N * 2];

int main(){
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> A[i];
    }

    for (int i=0;i<N;i++){
        B[i+1] = B[i] + A[i];
    }
    for (int i=0;i<N;i++){
        B[i+N+1] = B[i+N] + A[i];
    }

    if (B[N] % 10 != 0LL){
        cout << "No" << endl;
        return 0;
    }

    for (int i=0;i<N;i++){
        ll goal = B[i] + B[N] / 10;
        int pos = lower_bound(B, B + 2 * N + 1, goal) - B;
        if (B[pos] == goal){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;


    return 0;
}
