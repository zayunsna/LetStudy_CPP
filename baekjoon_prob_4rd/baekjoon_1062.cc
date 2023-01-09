#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

vector<string> l;
string str;
vector<char> w;
char d[5] = {'a', 'n', 't', 'i', 'c'};
int n, k;

int cnt = 0;
int ret = 0;

bool check(vector<char> vc){
	for(int i = 0; i < 5; ++i){
		if( find( vc.begin(), vc.end(), d[i]) == vc.end()) return false;
	}
	return true;
}

void baekjoon_1062(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		cin >> str;
		l.push_back(str);
		for(int j = 0; j < str.size(); ++j){
			w.push_back(str[j]);
		}
	}

	if( k < 5){
		cout << 0 << "\n";
		return;
	}

	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());

	for(auto it : w) cout << it << " ";
	cout << "\n";
	cout << " =====\n";
	int s = w.size();
	for(int i = 0; i < (1 << s); ++i){
		int t = 0;
		vector<char> va;
		for(int j = 0; j < s; ++j){
			if( i & (1 << j)){
				va.push_back(w[j]);
				t++;
			}
		}
		if( t == k && check(va)){
			for(auto it : va) cout << it << " ";
			cout << "\n";
			cnt = 0;
			for(int j = 0; j < n; ++j){
				string tar = l[j];
				tar.erase(0,4); tar.erase(tar.size()-4,tar.size());
				cout << tar << "\n";
				for(auto it : va){
					if( tar.find(it) != string::npos) tar.erase(tar.find(it));
				}
				cout << tar  << "  " << tar.size() << "\n";
				if(tar.size() == 0) cnt++;
			}
		}

		ret = max(cnt, ret);
	}

	cout << ret << "\n";

}
