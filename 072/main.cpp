#include<bits/stdc++.h>
using namespace std;

//inputs
int H, W;
char c[20][20];
bool visited[20][20];
int d[20][20];

int ans = 0;

void dfs(pair<int, int> u, pair<int, int> s){
	visited[u.first][u.second] = true;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for (int i=0;i<4;i++){
		pair<int, int> v;
		v.first = u.first + dx[i];
		v.second = u.second + dy[i];
		if (v.first >= H || v.first < 0 || v.second >= W ||  v.second < 0){
			continue;
		}
		if (s == v) {
			cout << v.first << " " << v.second << endl;
			ans++;
		}
		if (!visited[v.first][v.second] && c[v.first][v.second] == '.'){
			d[v.first][v.second] = d[u.first][u.second] + 1;
			dfs(v, s);
		}
	}
}

int main(){
	cin >> H >> W;
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			cin >> c[i][j];
		}
	}

	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			for (int k=0;k<H;k++){
				for (int l=0;l<W;l++){
					visited[k][l] = false;
					d[k][l] = 0;
				}
			}
			pair<int, int> root;
			root.first = i;
			root.second = j;
			dfs(root, root);
		}
	}

	cout << ans << endl;


	return 0;
}
