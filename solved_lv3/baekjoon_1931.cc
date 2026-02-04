#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

struct times{
	int start;
	int end;
};

bool compare(const times& a, times& b){
	if(a.end == b.end) return a.start < b.start;
	return a.end < b.end;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	vector<times> meetings(100000);
	for(int i = 0; i < n; ++i){
		
		cin >> meetings[i].start >> meetings[i].end;
	}

	sort(meetings.begin(), meetings.end(), compare);

	int count = 0;
	int lastEnd = 0;

	for(const auto& m : meetings){
		if(m.start >= lastEnd){
			count++;
			lastEnd = m.end;
		}
	}
	
	cout << count << endl;
	return 0;
}
