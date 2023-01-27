#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int Inf = 1e9;
int n, k;
int mat[N+4];
int vis[N+4];
vector<int> v;
int ret;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k >> n;
	for(int i = 0; i < n; ++i) cin >> mat[i];

	for(int i = 0; i < n; ++i){
		cout << i << "  " << mat[i] << "  " << vis[mat[i]] << "\n";
		if(!vis[mat[i]]){
			cout << " no visited \n";
			if(v.size() == k){
				cout << " Space is full \n";
				int last_idx = 0;
				int pos;
				for(int num : v){
					cout << " for(int num : v)" << num << "\n";
					int now = Inf;
					for(int j = i+1; j < n; ++j){
						cout << " for loop by j : " << j << "  " << mat[j] << "\n";
						if(num == mat[j]){
							cout << " => if num == mat[j] " << j << "  " << num << "  " << mat[j] << "\n";
							now = j;
							break;
						}
					}
					if(last_idx < now){
						cout << " ==> last_idx < now " << last_idx << "  " << now << "\n";
						last_idx = now;
						pos = num;
					}
				}
				cout << i << " out of vector loop with " << last_idx << "  " << pos << "\n";
				vis[pos] = 0;
				ret++;
				cout << " Before vector status ";
				for(int num : v) cout << num << " ";
				cout << "\n";
				v.erase(find(v.begin(), v.end(), pos));
				cout << " Pos : " << pos << "  " << vis[pos] << "  " << ret << "\n";
				cout << " After vector status ";
				for(int num : v) cout << num << " ";
				cout << "\n";
			}
			cout << " Push back in vector : " << mat[i] << "\n";
			v.push_back(mat[i]);
			vis[mat[i]] = 1;

		}
	}

	cout << ret << "\n";
	return 0;
}
