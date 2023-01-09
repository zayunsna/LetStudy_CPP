#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n, k;
string str;

vector<int> w;
vector<char> c;
vector<int> re;

int a[30];

int mx = 0;
void baekjoon_1062_ver2(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for(int i = 0 ; i < n; ++i){
		cin >> str;
		int _num = 0;
		for(int j = 0; j < str.size(); ++j){
			char z = str[j];
			c.push_back(str[j]);

			_num |= (1<< (z-'a'));
		}
		w.push_back(_num);
	}

	if( k < 5){
		cout << 0 << "\n";
		return;
	}

	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());

	for(int i = 0 ; i < (1<<c.size()); ++i){
		int cnt = 0;
		int _num = 0;
		for(int j = 0; j < c.size(); ++j){
			if(i & (1<<j)){
				char z = c[j];
				_num |= (1<<(z-'a'));
				cnt++;
			}
		}

		if(cnt == k){
			re.push_back(_num);
		}
	}

	cout << re.size() << "  " << w.size() << "\n";
	for(int comp : re){
		int ret = 0;
		for(int tar : w){
			if( (tar & comp) == tar ) ret++;
		}
		mx = max(ret, mx);
	}

	cout << mx << "\n";


}
