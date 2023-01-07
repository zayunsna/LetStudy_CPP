#include<bits/stdc++.h>
#define maxn 200005
typedef long long ll;
using namespace std;   
const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1}; 
int n, a[44], ret = INF;
string s; 
void go(int here){
	cout << " now here " << here << "\n";
	\
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j){
			cout << a[i*n+j] << " ";
		}
		cout << "\n";
	}
	if(here == n + 1){
		cout << " final array in \n";
		int sum = 0; 
		for(int i = 0; i < n; i++){
            int bit = 1 << i;
			int cnt = 0; 
			for(int j = 1; j <= n; j++) {
				if(a[j] & bit)cnt++;
				cout << bitset<3>(a[j]) << "  " << bitset<3>(bit) << "  " << (a[j] & bit) << "  " << cnt << "\n";
			}
			cout << " check : " << cnt << "  " << n - cnt << " " << sum << "\n";
			sum += min(cnt, n - cnt); 
		}
		cout << " ==> " << ret << " vs " << sum << "\n";
		ret = min(ret, sum);
		return;
	}
	cout << " go there " << here+1 << "\n";
	go(here + 1);
	cout << " What? : " << a[here] << "\n";
	a[here] = ~a[here];
	cout << " and What? : " << a[here] << "\n";
	cout << " 2nd go there " << here+1 << "\n";
	go(here + 1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; 
	for(int i = 1; i <= n; i++){
		cin >> s; 
		int value = 1; 
		for(int j = 0; j < s.size(); j++){
			if(s[j] == 'T')a[i] |= value; 
			value *= 2;
		}
	} 
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j){
			cout << a[i*n+j] << " ";
		}
		cout << "\n";
	}
	go(1);
	cout << ret << "\n";
    return 0;
}
