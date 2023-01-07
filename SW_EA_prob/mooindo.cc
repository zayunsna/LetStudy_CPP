#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

/*
 * this code is actuallu works.
 * but if N is larger than 5, it caused time limit issue.
 * It too brust code to treat many case problem.
 * it should be solved by 'bit masking' , not a simple bfs search.
 * Strongly required the study for 'bit masking' .
 */


int Nevt;

const int N = 25;
const int S = 5;

typedef pair<int,int> Pair;

vector<Pair> boxCont[N][S];
Pair boxStat[N][S];
int boxH[N][S];
int vis[N];
vector<tuple<int,int,int>> vt;
int n, x, y, z;

bool check(Pair a, Pair b){
	if(a.first >= b.first && a.second >= b.second) return true;
	else if( a.first >= b.second && a.second >= b.first ) return true;
	else return false;
}


void setBox(){

	for(int i = 0; i < n; ++i){
		for( int in = i+1; in < n; in++){
			for(int j = 0; j < 3; ++j){
				for(int k = 0; k < 3; ++k){
					if(check( boxStat[i][j], boxStat[in][k])){
						boxCont[i][j].push_back(make_pair(in,k));
					} 
					if(check( boxStat[in][j], boxStat[i][k])){
						boxCont[in][j].push_back(make_pair(i,k));
					} 
				}
			}
		}
	}

}

int dfs(int nBox, int stat, int cnt){
	//cout << "Input : " << nBox << "  " << stat << "  " << cnt << "\n";
	if(cnt == n) return 0;
	int ss = boxCont[nBox][stat].size();
	//cout << " array Size : " << ss << "\n";
	if( ss == 0) return boxH[nBox][stat];
	int ret = boxH[nBox][stat];
	vis[nBox] = 1;
	//cout << " Heiht : " << ret << "\n";
	for(int i = 0; i < ss; ++i){
		auto it = boxCont[nBox][stat][i];
		if( vis[it.first] )continue;
		//cout << " -> Visited " << it.first << " : " << it.second << "\n";
		vis[it.first] = 1;
		//cout << " Start  Cal " << cnt+1 << " th height \n";
		int next_stack = dfs( it.first, it.second, cnt+1) + boxH[nBox][stat];
		//cout << " Cal done : " << next_stack<< "\n\n";
		ret = max(ret, next_stack);
		vis[it.first] = 0;
	}

	return ret;


}
void Init(){
	vt.clear();
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < 3; ++j){
			boxCont[i][j].clear();
		}
	}
	memset(boxStat, 0, sizeof(boxStat));
	memset(boxH, 0, sizeof(boxH));
	memset(vis, 0, sizeof(vis));
}

void mooindo(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> Nevt;
	for(int ievt = 0; ievt < Nevt; ++ievt){
		Init();
		cin >> n;
		for(int i = 0; i < n; ++i){
			cin >> x >> y >> z;
			vt.push_back(make_tuple(x,y,z));
			boxStat[i][0] = make_pair(x,y);
			boxStat[i][1] = make_pair(y,z);
			boxStat[i][2] = make_pair(x,z);
			boxH[i][0] = z;
			boxH[i][1] = x;
			boxH[i][2] = y;
		}

		setBox();


		int ref = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < 3; ++j)
				ref = max( dfs(i,j,0) , ref);
		}

		cout <<"#"<<ievt << " "<< ref << "\n";
	}

}
