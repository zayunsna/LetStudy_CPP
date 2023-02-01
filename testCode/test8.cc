#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	vector<int> v[3];
	v[0].push_back(1);
	v[0].push_back(2);
	v[1].push_back(1);
	v[2].push_back(1);
	v[2].push_back(2);
		
	vector<int> temp[3];
	temp[0].push_back(7);
	temp[1].push_back(7);
	temp[2].push_back(7);
	
	for(int i = 0; i < 3; ++i){
		cout << i << " : ";
		for(auto it : v[i]) cout << it << " ";
		cout << "\n";
	}
	
	v = temp;
 	for(int i = 0; i < 3; ++i){
		cout << i << " : ";
		for(auto it : v[i]) cout << it << " ";
		cout << "\n";
	}
}	
