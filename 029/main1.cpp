#include<bits/stdc++.h>
using namespace std;
//const
const int MAX_W = 9005;
//input
int W, N;
int A[MAX_W];
int main(){
    cin >> W >> N;
    for (int i=1;i<=W;i++){
        A[i] = 0;
    }
    for (int i=1;i<=N;i++){
        int L, R;cin >> L >> R;
        int height = *max_element(A+L, A+R+1) + 1;
        cout << height << endl;
        for (int j=L;j<=R;j++){
            A[j] = height;
        }
    }

    return 0;
}
