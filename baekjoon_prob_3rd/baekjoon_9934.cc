#include <bits/stdc++.h>
using namespace std;

const int N = 10;
vector<int> lt;
vector<int> v[N+2];
int n, m;

void makeTree(vector<int> vec, int depth){
	
	int sSize = vec.size();

	if(sSize == 1){
		v[depth].push_back(vec[0]);
		return;
	}
	
	int midle = sSize/2;
	v[depth].push_back(vec[midle]);
	
	vector<int> front, behind;
	front.assign(vec.begin(), vec.begin()+midle);
	behind.assign(vec.begin()+midle+1, vec.end());
	
	makeTree(front, depth+1);
	makeTree(behind, depth+1);

	return;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	string str = "";
	int end = pow(2,n)-1;
	for(int i = 0; i < end; ++i){
		cin >> m;
		lt.push_back(m);
	}
	makeTree(lt, 0);

	for(int i = 0; i < n; ++i){
		for(auto it : v[i]) cout << it << " ";
		cout << "\n";
	}
	
	return 0;
}
