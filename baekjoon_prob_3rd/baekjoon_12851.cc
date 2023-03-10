#include <bits/stdc++.h>
using namespace std;

const int N = 200004;
long long lt[N];
int vis[N];
int n,m;

void bfs(int j){

	queue<int> q;
	q.push(j);
	vis[j] = 1;
	lt[j] = 1;
	while(q.size()){
		int _num = q.front(); q.pop();
		for(int next : {_num+1, _num-1, _num*2}){
			if(0 <= next && next <= N){
				if(!vis[next]){
					q.push(next);
					vis[next] = vis[_num] + 1;
					lt[next] += lt[_num];
				}
				else if(vis[next] == vis[_num]+1){
					lt[next] += lt[_num];
				}
			}
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
	cout << vis[m]-1 << "\n";
	cout << lt[m] <<  "\n";

	return 0;
}
