#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

int n, c, a;
map<int,int> m;
vector<int> order;

bool cmp(pair<int,int> &a, pair<int, int> &b){


	if(a.second == b.second) {
		auto a_pos = find(order.begin(), order.end(), a.first);
		auto b_pos = find(order.begin(), order.end(), b.first);
//		cout << a.first << "  " << a.second << "[" << *a_pos << "]\n";
//		cout << b.first << "  " << b.second << "[" << *b_pos << "]\n";
		return a_pos < b_pos;
	}
	return a.second > b.second;

}

void baekjoon_2910(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	for(int i = 0 ;i < n; ++i){
		cin >> a;
		m[a]++;
		if( find(order.begin(), order.end(), a) == order.end()) order.push_back(a);
	}

	vector<pair<int,int>> p(m.begin(), m.end());

	sort(p.begin(), p.end(), cmp);

	for(auto it : p){
		for(int j = 0; j < it.second; ++j){
			cout << it.first << " ";
		}
	}
	cout << "\n";


}
