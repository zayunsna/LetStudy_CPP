#include <bits/stdc++.h>
using namespace std;

const int N = 200004;
long long lt[N];
int vis[N];
int save[N];
int ret;
int n,m;

void bfs(int j){

	queue<int> q;
	q.push(j);
	vis[j] = 1;
	while(q.size()){
		int _num = q.front(); q.pop();
		if( _num == m){
			ret = vis[m];
			break;
		}
		for(int next : {_num+1, _num-1, _num*2}){
			if(next >= N || next < 0 || vis[next]) continue;
			
			vis[next] = vis[_num] + 1;
			save[next] = _num;
			q.push(next);
			
		}
	}
	return;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	
	if(n == m){
		cout << 0 << "\n" << 1 << "\n";
		return 0;
	}
	bfs(n);
	vector<int> v;
	for(int i = m ; i != n; i = save[i]){
		v.push_back(i);
	}
	v.push_back(n);
	reverse(v.begin(), v.end());
	cout << ret -1 << "\n";
	for(auto it : v) cout << it << " ";
	cout << "\n";


	return 0;
}
