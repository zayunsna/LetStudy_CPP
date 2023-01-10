#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void baekjoon_14729(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<double, vector<double>, greater<double>> pq;

	int n;
	double score;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> score;
		pq.push(score);
	}

	cout << fixed;
	cout << setprecision(3);
	for(int i = 0; i < 7; ++i){
		cout << pq.top() << "\n";
		pq.pop();
	}

	cout << "\n";

}
