#include <bits/stdc++.h>
using namespace std;

int n, m, val;
int arr[104];
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; ++ i){
		cin >> arr[i];
	}

	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			for(int k = j+1; k < n; ++k){
				int sum = arr[i]+arr[j]+arr[k];
				if(sum <= m) v.push_back(sum);
			}
		}
	}
	sort(v.begin(), v.end(), greater<int>());

	cout << v[0] << "\n";

	return 0;
}
