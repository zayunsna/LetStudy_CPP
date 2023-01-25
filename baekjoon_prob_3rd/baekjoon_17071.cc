#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 500000;
int vis[2][N+4];
int turn = 1;


void bfs(int start, int end){
	queue<int> q;
	q.push(start);
	vis[0][start] = 1;
	cout << " Start : " << start << "  " << end << "  " << turn << "\n";

	int flag = 0;
	int temp_end = end;
	while(q.size()){
		temp_end += turn;
		cout << " Dong position : " << temp_end << " at turn " << turn <<  "\n";
		if(temp_end > N) break;
		cout << " vis check : " << turn%2 << "  " << temp_end << "  " << vis[turn%2][temp_end] << "\n";
		if(vis[turn%2][temp_end]){
			flag = 1;
			break;
		}
		int _size = q.size();
		cout << " Queue size : " << _size << "\n";
		for(int i = 0; i < _size ; ++i){
			int it = q.front(); q.pop();
			cout << " Next : " << it << "\n";
			for(auto next : {it+1, it-1, it*2}){
				if(next > 500000 || next < 0) continue;
				if(vis[turn%2][next])continue;
				vis[turn%2][next] = vis[(turn+1)%2][it]+1;
				cout << next << "  " << turn%2 << "  " << (turn+1)%2 << "  " << vis[turn%2][next] << "\n";
				if(next == temp_end){
					flag = 1;
					break;
				}
				q.push(next);
			}
			if(flag) break;
		}
		if(flag) break;
		turn++;
	}
	if(flag){
		cout << turn << "\n";
	}
	else cout << "-1\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	if(n == m){
		cout << 0 << "\n";
		return 0;
	}

	bfs(n,m);

	return 0;
}
