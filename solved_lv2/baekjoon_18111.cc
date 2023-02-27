#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
const int N = 250000;
int arr[N+4];
vector<pair<int,int>> vp;
int n, m, ori;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first) return p1.second > p2.second;
    return p1.first < p2.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> ori;
    for (int i = 0; i < n * m; i++)
        cin >> arr[i];

    for (int i = 0; i <= 256; i++){
        int now = i; 
        int iHave = ori;
        int t = 0, u = 0, d = 0;
        for (int j = 0; j < n * m; j++)
			if( (arr[j] - now ) >= 0){
				d += abs(arr[j] - now);
			}
			else{
				u += abs(arr[j] - now);
			}
        t += (d * 2);
        iHave += d;
        if (u > iHave) continue;
        t += u;
        vp.push_back({t, now});
    }
    sort(vp.begin(), vp.end(), cmp);
    cout << vp[0].first << " " << vp[0].second << "\n";

	return 0;
}
