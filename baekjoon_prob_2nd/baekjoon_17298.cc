#include <bits/stdc++.h>
using namespace std;

const int N = 1000004;
stack<int> s;
int arr[N];
int ret[N];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	memset(ret, -1, sizeof(ret));
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		while(s.size() && arr[s.top()] < arr[i]){
			ret[s.top()] = arr[i]; s.pop();
		}
		s.push(i);
	}
	
	for(int i = 0; i < n; ++i) cout << ret[i] << " ";
	cout << "\n";

	
	return 0;
}
