#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

int sumIt(const string& parts){
	int s = 0;
	int _this = 0;
	for(char c : parts){
		if(c == '+'){
			s += _this;
			_this = 0;
		}
		else{
			_this = _this*10 + (c - '0');
		}
	}
	s += _this;
	return s; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string inp;
	cin >> inp;

	vector<string> p;
	string _this;
	for(char c: inp){
		if (c == '-'){
			p.push_back(_this);
			_this.clear();
		}
		else{
			_this.push_back(c);
		}
	}
	p.push_back(_this);

	int res = sumIt(p[0]);
	for(int i = 1 ; i < (int)p.size(); ++i){
		res -= sumIt(p[i]);
	}

	cout << res << endl;
	return 0;
	
}
