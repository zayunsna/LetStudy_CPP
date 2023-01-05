#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int mat[100];
vector<int> adj[100];

int n = 10;
int lt[14];
int user[4];

int move(int n, int cnt){
	if(n == 99) return 99; // End Position
	if(adj[n].size() >= 2){
		n = adj[n][1]; 
		cnt--;
	}
	if(cnt){
		queue<int> q;
		q.push(n);
		int next;
		while(q.size()){
			int x = q.front(); q.pop();
			next = adj[x][0];
			//cout << " ---------"<< cnt <<"- " << x << " -> " << next << "\n";
			q.push(next);
			if(next == 99) break;
			cnt--;
			if(cnt == 0) break;
		}
		return next;
	}
	else{
		return n;
	}
}

bool checkUser(int pos, int id){
	if(pos == 99) return false;
	for(int i = 0; i <4; ++i){
		if( i == id ) continue;
		if(user[i] == pos) return true;
	}
	return false;
}

int run(int turn){
	if(turn == n) return 0;
	int ret = 0 ;
	//cout << " Turn : " << turn << ", Dice # is :" << lt[turn] << "\n";
	for(int i = 0; i < 4; ++i){
		//cout << " Current User ID : " << i << "\n";
		int temp_pos = user[i];
		//cout << " Current Position : " << temp_pos << "\n";
		int now_pos = move(temp_pos, lt[turn]);
		//cout << "   will move here : " << now_pos << "\n";
		if( checkUser(now_pos, i)) {
			//cout << " @@ This slot have already other Users \n";
			continue;
		}
		//cout << " Set User [" << i << "] position at " << now_pos << ", and make a point : " <<mat[now_pos] << "\n";
		user[i] = now_pos;
		//cout << " Current total score is : " << ret + mat[now_pos] << "\n";
		//cout << " Run next turn! \n";
		int next_run = run(turn+1) + mat[now_pos];
		//cout << " Comparing with next run : " << ret << " : " << next_run << "\n";
		ret = max(ret, next_run);
		//cout << " Go back for new combination at " << turn << "with socre " << ret <<"\n";
		user[i] = temp_pos;
	}

	return ret;

}

void add(int n, int p){
	adj[n].push_back(p);
}

void setMat(){
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


void baekjoon_17825(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	setMat();
	for(int i = 0; i < n; ++i) cin >> lt[i];
	cout << run(0) << "\n";



}
