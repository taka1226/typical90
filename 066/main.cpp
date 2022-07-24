#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 105;

int N;
int L[MAX_N];
int R[MAX_N];

int main(){
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> L[i] >> R[i];
    }

    double ans = 0;
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            int cnt = 0;
            for (int k=L[i];k<=R[i];k++){
                for (int l=L[j];l<=R[j];l++){
                    if (k > l) cnt++;
                }
            }
            double e = (double)cnt / (double)((R[i] - L[i] + 1) * (R[j] - L[j] + 1));
            ans += e;
        }
    }

    printf("%.12lf", ans);
    return 0;
}
