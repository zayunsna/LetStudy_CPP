#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int arr[N+4][8];
int temp[N+4][8];
int vis[N+4];
int n, k;
string str;
vector<pair<int,int>> vp;


void rotateArr(int T, int dir){

//	cout << " In rotateArr \n";
//	for(int i = 0; i < 8; ++i){	cout << arr[T][i] << " ";} cout << "\n";
//	for(int i = 0; i < 8; ++i){	cout << temp[T][i] << " ";} cout << "\n";
	if(dir == -1){
		for(int i = 1; i < 8; ++i){
			temp[T][i-1] = arr[T][i];
		}
		temp[T][7] = arr[T][0];
	}
	else if(dir == 1){
		for(int i = 1; i < 8; ++i){
			temp[T][i] = arr[T][i-1];
		}
		temp[T][0] = arr[T][7];
	}
	else if(dir == 0){
		for(int i = 0; i < 8; ++i){
			temp[T][i] = arr[T][i];
		}
	}
//	cout << "After \n";
//	for(int i = 0; i < 8; ++i){	cout << arr[T][i] << " ";} cout << "\n";
//	for(int i = 0; i < 8; ++i){	cout << temp[T][i] << " ";} cout << "\n";

}


void solve(int T, int cdir, int mdir){

//	cout << " Input : " << T << "  " << cdir << "  " << mdir <<  "\n";
	if(T < 0 || T >= n){
		return;
	}
	if(mdir == 1){
		if(arr[T][6] != arr[T-1][2]){
			rotateArr(T, cdir*-1);
			solve(T+1, cdir*-1, 1);
		}
		else{
			rotateArr(T, 0);
			solve(T+1, 0, 1);
		}
	}
	else if(mdir == -1){
		if(arr[T][2] != arr[T+1][6]){
			rotateArr(T, cdir*-1);
			solve(T-1, cdir*-1, -1);
		}
		else{
			rotateArr(T, 0);
			solve(T-1, 0, -1);
		}
	}
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> str;
		int sSize = str.size();
		for(int j = 0; j < sSize; ++j){
			arr[i][j] = (int)str[j] - '0';
		}
	}
	cin >> k;
	for(int i = 0; i < k; ++i){
		int a, b;
		cin >> a >> b;
		vp.push_back({a-1,b});
	}

	for(auto it : vp){

		memset(temp, 0, sizeof(temp));
		rotateArr(it.first, it.second);
		solve(it.first+1, it.second, 1);
		solve(it.first-1, it.second, -1);

		memcpy(arr, temp, sizeof(arr));
	}

	int ret = 0;
	for(int i = 0; i < n; ++i){
		if(arr[i][0] == 1) ret++;
	}

	cout << ret << "\n";

	return 0;
}
