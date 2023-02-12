#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	
	int tc;
	cin >> tc;
	for(int i = 0; i < tc; ++i){
		queue<pair<int,int>> q;
		vector<int> sq;	
		
		cin >> n >> m;
		for(int j = 0; j < n; ++j){
			int a; cin >> a;
			q.push({a,j});
			sq.push_back(a);
		}
		sort(sq.begin(), sq.end(), greater<int>());
		int cnt = 0;
		while(q.size()){
			auto it = q.front(); 
			int high = sq[cnt];
			
			if(it.first == high){
				q.pop(); 
				if( it.second == m ) {
					cout << cnt+1 << "\n";
					break;
				}
				cnt++;
			}
			else{
				q.push({it.first, it.second});
				q.pop();
			}
		}
		
	}	
	return 0;
}
