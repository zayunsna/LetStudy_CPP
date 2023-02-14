#include <bits/stdc++.h>
using namespace std;
int n, ret;

bool check(string str, int val){
	int sSize = str.size();
	int main = atoi(str.c_str());
	int sum = 0;
	for(int i = 0; i < sSize; ++i){
		sum += (int)str[i] - '0';
	}

	if(main + sum == val) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = n-100; i<= n; ++i){
		if(check(to_string(i), n)){
			ret = i;
			break;
		}
	}

	cout << ret << "\n";

	return 0;
}
