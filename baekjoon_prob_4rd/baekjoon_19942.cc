#include <bits/stdc++.h>
using namespace std;



map<int, vector<vector<int>>> ret_m;

struct A{
	int mp, mf, ms, mv, cost;
}a[20];

int n, sum, b, c, d, e;
int cri[5];
const int Inf = 999999999;
int ret = Inf;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < 4; ++i){
		cin >> cri[i];
	}
		
	for(int i = 0; i < n; ++i){
		int mp, mf, ms, mv, cost;
		cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
	}
	
	for(int i = 0; i < (1 << n); ++i){
		b = c = d = e = sum = 0;
		vector<int> v;
		for(int j = 0; j < n; ++j){
			if(i & (1<<j)){
				v.push_back( j+ 1);
				b += a[j].mp;
				c += a[j].mf;
				d += a[j].ms;
				e += a[j].mv;
				sum += a[j].cost;
			}
		}
		if( b >= cri[0] && c >= cri[1] && d >= cri[2] && e >= cri[3]){
			if(ret >= sum){
				ret = sum;
				ret_m[ret].push_back(v);
			}
		}
	}
	if(ret == Inf){
			cout << -1 << "\n";
	}
	else{
		cout << ret << "\n";
		auto it = ret_m[ret];
		sort(it.begin(), it.end());
		for( auto it2 : it[0]) cout << it2 << " ";
		}	
		return 0;
}

/*
typedef vector<pair<int,int>> vp;
int n, m;

int cache[1<<20];
const int Inf = 999999999;
vector<tuple<int,int,int,int,int>> v;
int cri[5];
vector<int> sol;

void run(int turn, int mp, int mf, int ms, int mv, int cost, int vis){
	//int &ret = cache[vis];
	if(mp >= cri[0] && mf >= cri[1] && ms >= cri[2] && mv >= cri[3] ){
		sol.push_back(vis);
		cache[vis] = cost;
		return;
	} 
	
	for(int i = 1; i <= n; ++i){
		if( vis & ( 1<<(i-1) ) ) continue;
		int newvis = vis | (1<<(i-1));
		//cout << bitset<20>(newvis) << "\n";
		auto it = v[i];
		int nmp, nmf, nms, nmv, ncost;
		tie(nmp, nmf, nms, nmv, ncost) = it;
		if(nmp < cri[0] || nmf < cri[1] || nms < cri[2] || nmv < cri[3]){
			run(i, mp+nmp, mf+nmf, ms+nms, mv+nmv, cost+ncost, newvis);
		}
	}
	return ;
}

void bitToSeq(int num){
	bitset<20> bit = num;
	string seq = bit.to_string();
	vector<int> lt;
	
	for(int i = 1 ; i <= 20; ++i){
		if( seq[i] == '1' ) lt.push_back(abs(i-21));
	}
	sort(lt.begin(), lt.end());
	for(auto it : lt) cout << it << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < 4; ++i){
		cin >> cri[i];
	}
		
	for(int i = 0; i < n; ++i){
		int mp, mf, ms, mv, cost;
		cin >> mp >> mf >> ms >> mv >> cost;
		v.push_back(make_tuple(mp,mf,ms,mv,cost));
	}
	
	run(0,0,0,0,0,0,0);
	
	cout << " Search end \n";
	
	int minCost = Inf;
	int minTurn = 0;
	if(sol.size() == 0){
		cout << -1 <<"\n";
		return 0;
	}
	for(int i = 0; i < sol.size(); ++i){
		if(minCost > cache[sol[i]]) {
			minCost = cache[sol[i]];
			minTurn = i;
		}
	}
	cout << minCost << "\n";
	bitToSeq(sol[minTurn]);
	return 0;
}
*/
