#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m, k, a;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k >> m;
	vector<vector<int>> station(n+1);
	vector<vector<int>> tube(m+1);
	vector<int> vis_station(n+1, -1);
	vector<int> vis_tube(m+1, -1);
	for(int i = 1; i <= m; ++i){
		for(int j = 0; j < k; ++j){
			cin >> a;
			tube[i].push_back(a);
			station[a].push_back(i);
		}
	}
	
	queue<int> q;
	q.push(1);
	vis_station[1] = 1;
	while(q.size()){
		int now = q.front(); q.pop();
		for(int i = 0; i < station[now].size(); ++i){
			int next = station[now][i];
			if(vis_tube[next]== -1){
				vis_tube[next] = 1;
				for(int j = 0; j < tube[next].size(); ++j){
					int next_station = tube[next][j];
					if(vis_station[next_station] == -1){
						vis_station[next_station] = vis_station[now]+1;
						q.push(next_station);
					}
				}
			}
		}
	}
	cout << vis_station[n] << "\n";
}
