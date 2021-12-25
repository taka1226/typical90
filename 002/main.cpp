#include<bits/stdc++.h>
using namespace std;

//input
int N;
int main(){
    cin >> N;
    for (int bit=0;bit<(1 << N);bit++){
        vector<int>V(N);
        for (int i=0;i<N;i++){
            if (bit & (1 << i)){
                V[N - 1 - i] = 1;
            }
        }

        int cnt = 0;
        int cnt0 = 0;
        int cnt1 = 0;
        bool flag = true;
        for (int i=0;i<N;i++){
            if (V[i] == 0){
                cnt++;
                cnt0++;
            }else if (V[i] == 1){
                cnt--;
                cnt1++;
            }

            if (cnt < 0){
                flag = false;
            }
        }
        if (flag && cnt0 == N / 2 && cnt1 == N / 2){
            for (auto& p : V){
                if (p == 0){
                    cout << "(";
                }else{
                    cout << ")";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
