#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	priority_queue<long long, vector<long long>, greater<long long>> pq;

    while (n--) {
        long long x;
        cin >> x;

        if (x > 0) {
            pq.push(x);
        } else {
            if (pq.empty()) {
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}
