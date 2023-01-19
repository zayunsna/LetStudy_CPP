#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 64;
const int Inf = 987654321;
int vis[N][N][N];
int dmg[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 3, 9},
	{1, 9, 3}
};
int n;
int a[3];
struct scv{
	int a, b, c;
};

int bfs(int s[3]){

	queue<scv> q;
	q.push({s[0],s[1],s[2]});
	vis[s[0]][s[1]][s[2]] = 1;

	while(q.size()){
		scv it = q.front(); q.pop();
		for(int i = 0; i < 6; ++i){
			int na = max(0, it.a - dmg[i][0]);
			int nb = max(0, it.b - dmg[i][1]);
			int nc = max(0, it.c - dmg[i][2]);

			if(vis[na][nb][nc]) continue;

			vis[na][nb][nc] = vis[it.a][it.b][it.c] + 1;
			q.push({na,nb,nc});
		}
	}

	return vis[0][0][0] - 1;
}



void baekjoon_12869(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}

	cout << bfs(a) << "\n";


}
