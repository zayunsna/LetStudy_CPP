#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
string str;

bool check(string ss){
	int s = ss.length();
	if(s%2 == 0){
		string a = ss.substr(0,s/2);
		string b = ss.substr(s/2,s);
		reverse(b.begin(), b.end());
		for(int i = 0; i < s/2; ++i){
			if(a[i] != b[i]) return false;
		}
	}
	else{
		string a = ss.substr(0, s/2);
		string b = ss.substr(s/2+1,s);
		reverse(b.begin(), b.end());
		for(int i = 0; i < s/2; ++i){
			if(a[i] != b[i]) return false;
		}
		
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true){
		cin >> str;
		if(str == "0") break;
		cout << (check(str) ? "yes" : "no") << "\n";
	}
	return 0;
}
