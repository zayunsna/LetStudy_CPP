#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 20;
const int Inf = 987654321;
int n, m;

struct in{
	int next, y, x;
};
vector<in> vp[N+4];
vector<int> dist;


void Init(){
	for(int i = 0; i < N+4; ++i)vp[i].clear();
	dist.clear();

}

vector<pair<int,int>> solve(int start, int node, vector<in> a[N+4]){
	vector<pair<int,int>> out(node+1, make_pair(Inf,Inf));
	priority_queue<tuple<int,int,int>> pq;
	
	out[start] = make_pair(0,0);
	pq.push(make_tuple(0,0,start));
	
	while(pq.size()){
		int cost_y = -get<0>(pq.top());
		int cost_x = -get<1>(pq.top());
		int cur = get<2>(pq.top());
		//cout << cost_y << "  " << cost_x << "  " << cur << "\n";
		pq.pop();
		
		for(int i = 0; i < a[cur].size(); ++i){
			int next = a[cur][i].next;
			int nCost_y = cost_y + a[cur][i].y;
			int nCost_x = cost_x + a[cur][i].x;
			int tCost_now = nCost_y * nCost_x;
			int tCost_next = out[next].first * out[next].second;
			if(out[next].first == Inf || out[next].second == Inf) tCost_next = Inf;
			//cout << i << "[" << cur << "->" << next << "]"<< " :: " << nCost_y << "  " << nCost_x << "  " << tCost_next << "  " << tCost_now << "\n"; 
			if(tCost_next > tCost_now){
				out[next] = make_pair(nCost_y, nCost_x);
				pq.push(make_tuple(-nCost_y, -nCost_x, next));
			}
			
		} 
	}
	
	return out;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;
	for(int ic = 1; ic <= tc; ++ic){
		Init();	
		cin >> n >> m;
		if(m == 0){
			cout << "#" << ic << " -1\n";	
			continue;
		} 
		for(int i = 0 ; i < m; ++i){
			int a, b, y, x;
			cin >> a >> b >> y >> x;
			vp[a].push_back({b,y,x});
			vp[b].push_back({a,y,x});
		}
		
		
		vector<pair<int,int>> out = solve(1, m, vp);
		int y = out[2].first;
		int x = out[2].second;
		int ret = x*y;
		if(ret >= Inf) cout << "#" << ic << " " << -1 << "\n";
		else cout << "#" << ic << " " << ret << "\n";
	}
	return 0;
}
