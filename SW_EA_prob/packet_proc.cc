
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

void run(int nCPU, int prev, int cnt){
	if(cnt == n){
		mx = nCPU;
		return;
	}
	
	pair<int,int> p = vp[cnt];
	cout  << "== Input : "<< p.first << "  " << p.second << "  " << cnt << "\n";
	
	int temp[5];
	if(prev < p.first){
		int diff = p.first - prev;
		for(int i = 0; i < nCPU; ++i){
			cout << queSum[i] << " -> ";
			temp[i] = (queSum[i] - diff <= 0) ? 0 : queSum[i] - diff ;
			cout << queSum[i] << "\n";
		}
	}

	for(int i =0 ; i < nCPU; ++i){
		if(temp[i] + p.second > limit) {
			continue;
		}
		queSum[i] = temp[i] + p.second;
		run(nCPU, p.first, cnt +1);
		queSum[i] = temp[i] - p.second;
		
	}

}

void proc(){
	for(int i = 1; i <= 5; ++i){
		memset(queSum, 0, sizeof(queSum));
		run(i, 0, 0);
		if( mx > 0) break;
	}
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int bias = 0;

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> tg >> tl;
		if(i == 0) bias = tg;
		vp.push_back({tg-bias,tl});
	}

	proc();

	cout << mx << "\n";

}
