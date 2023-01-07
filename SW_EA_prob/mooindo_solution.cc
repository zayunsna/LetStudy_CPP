#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

int cache[21][1 << 20][3];
int infos[21][3], n;
int Inf = 99999999;

void swap(int &i1, int &i2) {
    int temp = i1;
    i1 = i2;
    i2 = temp;
}
 
 
int getLength(int now, int mode, int row, int col, int visit) {
    int &ret = cache[now][visit][mode];
	cout << "\n";
	cout << now << "  " << mode << "  " << row << "  " << col << "  " << bitset<3>(visit) << " = " << cache[now][visit][mode] << "\n";
    if (ret) return ret;
    
    for (int i = 1; i <= n; i++) {
        if (visit & (1 << (i-1))) {
			cout << i << " continued. \n";
			continue;
		}
		cout << " in For loop " << i << " ";
        int nv = visit | (1 << (i-1));
		cout << bitset<3>(nv) << " =  " << bitset<3>(visit) << " | " << bitset<3>(1<<(i-1)) << "\n";
        if (row >= infos[i][0] && col >= infos[i][1]) {
			cout << now << "/" << i << " => 1 " << row << " >= " << infos[i][0] << " && " << col << " >= " << infos[i][1] << "\n"; 
            ret = max(ret, infos[i][2] + getLength(i, 0, infos[i][0], infos[i][1], nv));
			cout << now << "/" << i << " => 1 " << ret  << " MAX \n";
        }
        if (row >= infos[i][0] && col >= infos[i][2]) {
			cout << now << "/" << i << " => 2 " << row << " >= " << infos[i][0] << " && " << col << " >= " << infos[i][2] << "\n"; 
            ret = max(ret, infos[i][1] + getLength(i, 1, infos[i][0], infos[i][2], nv));
			cout << now << "/" << i << " => 2 " << ret  << " MAX \n";
        }
 
        if (row >= infos[i][1] && col >= infos[i][2]) {
			cout << now << "/" << i << " => 3 " << row << " >= " << infos[i][1] << " && " << col << " >= " << infos[i][2] << "\n"; 
            ret = max(ret, infos[i][0] + getLength(i, 2, infos[i][1], infos[i][2], nv));
			cout << now << "/" << i << " => 3 " << ret  << " MAX \n";
        }
    }
	cout << " End for loop : " << ret << "\n";
    return ret;
}
 

void mooindo_solution(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
    infos[0][2] = infos[0][0] = infos[0][1] = Inf;

    for (int tc = 1; tc <= t; tc++) {
		cin >> n;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 1 << (n); j++) {
                for (int k = 0; k < 3; k++) cache[i][j][k] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
			cin >> infos[i][0] >> infos[i][1] >> infos[i][2];
            if (infos[i][0] > infos[i][1]) swap(infos[i][0], infos[i][1]);
            if (infos[i][1] > infos[i][2]) swap(infos[i][1], infos[i][2]);
            if (infos[i][0] > infos[i][1]) swap(infos[i][0], infos[i][1]);
        }

		cout << "#" << tc << " " << getLength(0, 0, Inf, Inf, 0) << "\n";
    }

}
