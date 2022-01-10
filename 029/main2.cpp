#include<bits/stdc++.h>
using namespace std;
//const
const int MAX_W = 9005;

//input
int W, N;
int B[MAX_W];

int main(){
    cin >> W >> N;
    vector<int> A;
    vector<int> L(N+1);
    vector<int> R(N+1);
    for (int i=1;i<=N;i++){
        cin >> L[i] >> R[i];
        A.push_back(L[i]);
        A.push_back(R[i]);
    }

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for (int i=1;i<=N;i++){
        L[i] = lower_bound(A.begin(), A.end(), L[i]) - A.begin();
        R[i] = lower_bound(A.begin(), A.end(), R[i]) - A.begin();
    }

    for (int i=1;i<=N;i++){
        int height = *max_element(B+L[i], B+R[i]+1) + 1;
        cout << height << endl;
        for (int j=L[i];j<=R[i];j++){
            B[j] = height;
        }
    }


    return 0;
}
