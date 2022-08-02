#include<bits/stdc++.h>
using namespace std;
//const
const int MAX_H = 1005;
const int MAX_W = 1005;

//inputs
int H, W;
int rs, cs, rt, ct;
char S[MAX_H][MAX_W];
bool used[MAX_H][MAX_W];

int dist[MAX_H][MAX_W][4];
struct state {
	int x, y, dir;
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
	cin >> H >> W;
	cin >> rs >> cs;rs--;cs--;
	cin >> rt >> ct;rt--;ct--;
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			cin >> S[i][j];
		}
	}

	//distの初期化
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			dist[i][j][0] = INT_MAX;
			dist[i][j][1] = INT_MAX;
			dist[i][j][2] = INT_MAX;
			dist[i][j][3] = INT_MAX;
		}
	}
	deque<state> deq;
	for (int i=0;i<4;i++){
		dist[rs][cs][i] = 0;
		deq.push_back({rs, cs, i});
	}

	while (!deq.empty()){
		state u = deq.front(); deq.pop_front();
		for (int i=0;i<4;i++){
			int vx = u.x + dx[i];
			int vy = u.y + dy[i];
			int cost = dist[u.x][u.y][u.dir] + (u.dir != i ? 1 : 0);
			if (0 <= vx && vx < H && 0 <= vy && vy < W && S[vx][vy] == '.' && dist[vx][vy][i] > cost){
				dist[vx][vy][i] = cost;
				if (u.dir != i) deq.push_back({vx, vy, i});
				else deq.push_front({vx, vy, i});
			}
		}
	}
	int ans = INT_MAX;
	for (int i=0;i<4;i++){
		ans = min(ans, dist[rt][ct][i]);
	}

	cout << ans << endl;

	return 0;
}
