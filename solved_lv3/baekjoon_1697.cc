#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;

	int limit = 100001;
	int dist[limit];
	memset(dist, -1, sizeof(dist));
	dist[n] = 0;
	
	queue<int> q;
	q.push(n);
	
	while(!q.empty()){
		int cur = q.front(); q.pop();
		cout << "[POP] cur = " << cur << ", dist = " << dist[cur] << endl;
		
		if(cur == m){
			cout << "[FOUND] target = " << m << ", time = " << dist[cur] << endl;
			// cout << dist[cur] << endl;
			break;
		}
		
		if(cur-1 >= 0 && dist[cur-1] == -1){
			dist[cur-1] = dist[cur] + 1;
			cout << "  -> PUSH " << cur-1 << " (from " << cur << ", dist = " << dist[cur-1] << ")" << endl;
			q.push(cur-1);
		}
		if(cur+1 < limit && dist[cur+1] == -1){
			dist[cur+1] = dist[cur] + 1;
			cout << "  -> PUSH " << cur+1 << " (from " << cur << ", dist = " << dist[cur+1] << ")" << endl;
			q.push(cur+1);
		}
		if(cur*2 < limit && dist[cur*2] == -1){
			dist[cur*2] = dist[cur] + 1;
			cout << "  -> PUSH " << cur*2 << " (from " << cur << ", dist = " << dist[cur*2] << ")" << endl;
			q.push(cur*2);
		}
	}
}
