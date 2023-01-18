
#include <bits/stdc++.h>
using namespace std;

const int N = 50;
vector<int> v[N];
int n, target;
int cnt = 0;
int vis[N];

void dfs(int start, int target){
	
	//cout << " Input : " << start << "  " << target << "\n";
	
	if(v[start].size() == 0){
		cnt++;
		return;
	}
	vis[start] = 1;
	int s = v[start].size();
	for(int i = 0; i < s; ++i){
		int next = v[start][i];
		
		//cout << i << "  " << next << "\n";
		
		if(next == target) {
			if( s == 1) cnt++;
			continue;
		}
		vis[next] = 1;
		//cout << " Go Next Recursion with " << next << "\n";
		dfs(next, target);
		//cout << " Return From " << next << "\n";
		vis[next] = 0;
	}
	
	return;
	
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int mother = 0;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		if(a == -1) {
			mother = i; 
			continue;
		}
		v[a].push_back(i);
	}
	cin >> target;

	dfs(mother,target);
	
	if(target == mother) cout << 0 << "\n";
	else cout << cnt <<"\n";
}
