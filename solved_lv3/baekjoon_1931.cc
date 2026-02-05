#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int start;
    int end;
};

bool compareMeeting(const Meeting& a, const Meeting& b) {
    if (a.end != b.end) return a.end < b.end;   
    return a.start < b.start;                   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Meeting> meetings;
    meetings.reserve(N);

    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        meetings.push_back({s, e});
    }

    sort(meetings.begin(), meetings.end(), compareMeeting);

    int count = 0;
    int lastEnd = 0;

    for (const auto& m : meetings) {
        if (m.start >= lastEnd) {
            count++;
            lastEnd = m.end;
        }
    }

    cout << count << "\n";
    return 0;
}
