#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int n_test;
int n, tg,tl, prev_tg, prev_tl;
int limit = 10; // 10 sec
int maxCPU = 5;
vector<pair<int,int>> vp;

int initT[5];
int queSum[5];

int mx = 0;

void run(int start, int cnt){
	if(cnt == n){
		return;
	}

	pair<int,int> p = vp[cnt];
	for(int i = 0; i < 5; ++i){
		queSum[i] = (queSum[i] - p.first <= 0) ? 0 : queSum[i] - p.first ;
		int this_t = 0;		
		if(queSum[i] == 0){
			this_t = p.second;
		}
		else{
			this_t = queSum[i] + p.second;
		}

		if(this_t > limit){

		}
		
	}

}
/*
void run(int start,  int cnt){
	if(cnt == n){
		cout << " All entry is done \n";
		return;
	}
	pair<int,int> p = vp[cnt];
	int this_t = 0;
	cout << " Start : " << start << " | cnt " <<  cnt << "\n";
	cout << " ====> " << p.first << " : " << p.second << " | " << mx << "\n";
	for(int i = 0; i < 5; ++i){
		if(i == start )continue;
		mx = max(mx, i+1);
		if(queSum[i] == 0){
			initT[i] = p.first;
			this_t = p.second;
			cout << " Init T : " << initT[i] << "\n";
			cout << " 1 - This T : " << this_t << "\n"; 
		}
		else{
			this_t = queSum[i] + p.second - p.first + initT[i];
			cout << " 2 - This T : " << this_t << "\n";
		}
		if(this_t > limit){
			cout << " Packet T is large \n";
			cout << " will go " << i << " " << cnt << "\n";
			run(i, cnt);
			return;
		}
		else{
			cout << " Packet T can handled. \n";
			queSum[i] += p.second;
			cout << " qumSum[" << i << "] : " << queSum[i] << "\n";
			cout << " will go " << -1 << " " << cnt+1 << "\n";
			run(-1, cnt+1);
			return;

		}
	}
	return;

}
*/

void packet_proc(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int bias = 0;

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> tg >> tl;
		if(i == 0) bias = tg;
		vp.push_back({tg-bias,tl});
	}

	run(-1,0);

	cout << mx << "\n";

}
