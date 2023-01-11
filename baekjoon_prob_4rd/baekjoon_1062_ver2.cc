
#include <bits/stdc++.h>
using namespace std;

int n, k;
string str;

vector<int> w;
vector<char> c;
vector<int> re;

int a[30];

int base = 0;
char z[5] = {'a','n','t','c','i'};

void baseSet(){
	
	for(int i = 0; i < 5; ++i) base |= (1<<(z[i]-'a'));
}

int mx = 0;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	baseSet();

	cin >> n >> k;
	for(int i = 0 ; i < n; ++i){
		cin >> str;
		str.erase(0,4); str.erase(str.size()-4,str.size());
		//cout << str << "  " << str.size() << "\n";
		int _num = 0;
		for(int j = 0; j < str.size(); ++j){
			//cout << j << "\n";
			char z = str[j];
			c.push_back(str[j]);
			
			//cout << bitset<26>(base) << "  " << bitset<26>(_num) << "\n";
			_num |= base | (1<< (z-'a'));
			//cout << bitset<26>(base) << "  " << bitset<26>(_num) << "\n";
		}
		w.push_back(_num);		
	}

	if( k < 5){
		cout << 0 << "\n";
		return 0;
	}
	else k -= 5;

	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());

	for(int i = 0 ; i < (1<<c.size()); ++i){
		int cnt = 0;
		int _num = 0;
		for(int j = 0; j < c.size(); ++j){
			if(i & (1<<j)){
				char z = c[j];
				_num |= base | (1<<(z-'a'));
				if(z == 'a' && z == 't' && z == 'i' && z == 'c' && z == 'n') continue;
				else cnt++;
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
	return 0;

}
