#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

int n, m, s;
int a,b;
vector<int> v[1004];
vector<int> v_dfs;
vector<int> v_bfs;
int vis[1004];

void dfs(int start){
	vis[start] = 1;
	for(int i = 0; i < v[start].size(); ++i){
		if(!vis[v[start][i]]){
			v_dfs.push_back(v[start][i]);
			dfs(v[start][i]);
		}
	}
	return;
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	vis[start] = 1;
	while(q.size()){
		int it = q.front(); q.pop();
		for(int i =0 ; i < v[it].size(); ++i){
			if(!vis[v[it][i]]){
				q.push(v[it][i]);
				v_bfs.push_back(v[it][i]);
				vis[v[it][i]] = 1;
			}
		}
	}
	return;
}

void baekjoon_1260(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> s;

	for(int i =0 ;i < m; ++i){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i =0 ; i< n; ++i) sort(v[i].begin(), v[i].end());
	v_dfs.push_back(s);
	dfs(s);
	for(int i = 0; i < v_dfs.size(); ++i) cout << v_dfs[i] << " ";
	cout << "\n";
	fill(&vis[0], &vis[0] + 1004, 0);

	v_bfs.push_back(s);
	bfs(s);
	for(int i = 0; i < v_bfs.size(); ++i) cout << v_bfs[i] << " ";
	cout << "\n";

}
