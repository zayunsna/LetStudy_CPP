#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;
const int N = 100000;
int mem[N];
char arr[N];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	
	string str= "";
	for(int i = 0; i < n; ++i) str += arr[i];
	
	int cnt = 0;
	int l = 1;
	int num =0 ;
	
	string temp = "";
	while(1){
		for(int j = 0; j < n; ++j){
			temp = str.substr(j, l);
			num = atoi(temp.c_str());
			if(mem[num]) continue;
			mem[num] = 1;
			cnt++;
			cout << j << "  " << l << "  " << temp << "\n";
			if(j+l == n) break;
		}
		l++;
		if(l > n) break;
	}
	
	cout << cnt << "\n";
	
}
