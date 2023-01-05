#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

int n, m, f;
int a[21];
int cnt = 0;

void dfs(int start, int npos){
	if(start == f) return;
	int s = npos;
	int e = npos + (m-1);
//	cout << start << "  " << s << " ~ " << e << " = " << a[start] << " " << cnt << "\n";
	if( s <= a[start] && a[start] <= e){
//		cout << " Catch! " << s << " | " << a[start] << " | " << e << "\n";
		dfs(start+1, npos);
	}
	else if( s > a[start]){
//		cout << " Move Left " << s << " | " << a[start] << " | " << e << "\n";
		cnt++;
		dfs(start, npos-1);
	}
	else if( e < a[start]){
//		cout << " Move Right " << s << " | " << a[start] << " | " << e << "\n";
		cnt++;
		dfs(start, npos+1);
	}
	return;
}

void baekjoon_2828(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> f;
	for(int i = 0; i < f; ++i){
		cin >> a[i];
	}
	
	if(m == 1){
		for(int i = 1; i < f; ++i){
			cnt += abs(a[i-1]-a[i]);
		}
	}
	else {
		dfs(0,1);
	}


	cout << cnt << "\n";

}
