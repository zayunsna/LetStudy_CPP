#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 104;
vector<int> v[N];
int vis[N];
int n,m;
vector<pair<int,int>> vp;

bool cmp(pair<int,int> a, pair<int,int> b){
	if( a.second < b.second ){
		return a.first > b.first;
	}
	return a.first < b.first;
}

bool duCheck(int a, int b){
	if(find(v[a].begin(), v[a].end(), b) == v[a].end()) return true;
	return false;
}

int bfs(int start, int end){
	queue<int> q;
	q.push(start);
	vis[start] = 1;
	int flag = 0;
	//cout << start << "  " << end << "\n";
	while(q.size()){
		int it = q.front(); q.pop();
		for(int i = 0; i < v[it].size(); ++i){
			int next = v[it][i];
			//cout << i << "  [" << it << "]  " << next << " -> " << end << "\n";
			if(vis[next]) continue;
			vis[next] = vis[it] + 1;
			if( next == end) {
				flag = vis[next];
				break;
			}
			q.push(next);
		}
		if(flag) break;
	}

	//cout << " Return : " << start << "  " << end << " = " << flag-1 << "\n"; 
	return flag-1;
}

void baekjoon_1389(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		if(duCheck(a,b)) v[a].push_back(b);
		if(duCheck(b,a)) v[b].push_back(a);
	}

	for(int i = 1; i <= n; ++i){
		int sum = 0;
		for(int j = 1; j <= n; ++j){
			if( i == j) continue;
			memset(vis, 0, sizeof(vis));
			sum += bfs(i,j);
		}
		vp.push_back({i,sum});
	}

	sort(vp.begin(), vp.end(), cmp);

	cout << vp[0].first << "\n";



}
