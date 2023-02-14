#include <bits/stdc++.h>
using namespace std;

int n, ret;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	queue<int> q;
	for(int i = 1; i <= n; ++i){
		q.push(i);
	}

	while(true){
		if(q.size() == 1){
			ret = q.front();
			break;
		}
		q.pop();
		int it = q.front(); 
		q.push(it); 
		q.pop(); 
	}

	cout << ret << "\n";

	return 0;
}
