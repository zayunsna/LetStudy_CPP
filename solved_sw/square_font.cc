#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3;
const int Inf = 1e9;
int mat[N+4][N+4];
vector<int> v;
int h, w, k;
string str;
int ret;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;
	for(int ic = 1; ic <= tc; ++ic){
		v.clear();
		ret = 0;
		cin >> h >> w >> k;
		for(int i = 0; i < k; ++i){
			cin >> str;
			v.push_back(str.size());
		}
		//41 85 9
		//samsung i am man HELLO HI MAN 20 20

		for(int i = 1 ; i <= 1000; ++i){
			//cout << " Condition [W, H] = " << w << " : " << h << "\n";
			int total_w = 0;
			int total_h = i;
			int cnt = 0;
			for(int j = 0; j < v.size(); ++j){
				int cw = v[j]*i;
				if(cw > w) continue;
				total_w += cw;

				if(total_w > w){
					total_h += i;
					total_w = cw;
				}
				total_w += i;
				//cout << " Size : " << i << ", Word length : "  << v[j] << ", word total witdh : " << cw << ", Filled witdh : " << total_w << ", filled height : " << total_h << "\n";
				if(total_h > h) break;
				cnt++;
			}
			//cout << " -> " << i << "  " << cnt << "\n";
			if(cnt == k){
				ret = max(ret, i);
			}
			else if (cnt < k ) break;
		}

		cout << "#" << ic << " " << ret << "\n";
	}

}
