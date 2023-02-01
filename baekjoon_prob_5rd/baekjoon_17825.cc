#include <bits/stdc++.h>
#include <cstdbool>
using namespace std;

const int Inf = 1e9;
vector<int> v[40];
int mat[40];
int arr[11];
int user[4];
int n = 10;
int ret;

void add(int a, int b){
	v[a].push_back(b);
}

void setBoard(){

	for(int i = 0; i <= 19; ++i) add(i, i+1);
	add(5, 21); add(21, 22); add(22, 23); add(23, 24);
	add(10, 25); add(25, 26); add(26, 24);
	add(15, 29); add(29, 30); add(30, 31); add(31, 24);
	add(24, 27); add(27, 28); add(28, 20); add(20, 99);

	mat[1] = 2; mat[2] = 4; mat[3] = 6; mat[4] = 8; mat[5] = 10; mat[6] = 12; mat[7] = 14; mat[8] = 16;
	mat[9] = 18; mat[10] = 20; mat[11] = 22; mat[12] = 24; mat[13] = 26; mat[14] = 28; mat[15] = 30;
	mat[16] = 32; mat[17] = 34; mat[18] = 36; mat[19] = 38; mat[20] = 40; 
	mat[21] = 13; mat[22] = 16; mat[23] = 19; mat[24] = 25; 
	mat[25] = 22; mat[26] = 24; mat[27] = 30; mat[28] = 35;
	mat[29] = 28; mat[30] = 27; mat[31] = 26;


}

int move(int pos, int act){
	if(pos == 99) return 99;
	if(v[pos].size() >= 2){
		pos = v[pos][1];
		act--;
	}
	if(act){
		queue<int> q;
		q.push(pos);
		int next;
		while(q.size()){
			int x = q.front(); q.pop();
			next = v[x][0];
			q.push(next);
			if(next == 99) break;
			act--;
			if(act == 0) break;
		}
		return next;
	}
	else return pos;
}

bool checkUser(int pos, int id){
	if(pos == 99) return false;
	for(int i = 0; i < 4; ++i){
		if(i == id) continue;
		if(user[i] == pos) return true;
	}
	return false;
}

int solve(int turn){
	if(turn == n){
		return 0;
	}

	int ret = 0;
	for(int i = 0; i < 4; ++i){
		int temp_pos = user[i];
		int now_pos = move(temp_pos, arr[turn]);
		if(checkUser(now_pos, i)) continue;
		user[i] = now_pos;
		int next_run = solve(turn+1) + mat[now_pos];
		ret = max(ret, next_run);
		user[i] = temp_pos;
	}

	return ret;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	setBoard();
	for(int i = 0; i < 10; ++i){
		cin >> arr[i];
	}

	int ret = solve(0);

	cout << ret << "\n";

 //	for(int i = 0; i < 40; ++i){
 //		for(int it : v[i]) cout << it << " ";
 //		cout << "\n";
 //	}

	return 0;
}
