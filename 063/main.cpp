#include<bits/stdc++.h>
using namespace std;
//const
const int MAX_W = 10005;
//inputs
int H, W;
int P[10][MAX_W];


int main(){
	cin >> H >> W;
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			cin >> P[i][j];
		}
	}

	int ans = -1;

	for (int bit=0;bit < (1 << H);bit++){
		map<int, int> mp;
		for (int i=0;i<W;i++){
			set<int> st;
			for (int j=0;j<H;j++){
				if (bit & (1 << j)){
					st.insert(P[j][i]);
				}
			}
			if (st.size() == 1){
				int key = *st.begin();

				for (int j=0;j<H;j++){
					if (bit & (1 << j)){
						mp[key]++;
					}
				}
			}
		}

		for (auto [x, y]: mp){
			ans = max(ans, y);
		}
	}


	cout << ans << endl;

	return 0;
}
