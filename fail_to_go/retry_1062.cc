#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<string> words;
int maxReadable = 0;
vector<char> essential = {'a', 'n', 't', 'i', 'c'};
set<char> unique_chars;

void countReadableWords(vector<char> &selected_chars) {
    int count = 0;
    for (string word : words) {
        bool canRead = true;
        for (char ch : word) {
            if (find(selected_chars.begin(), selected_chars.end(), ch) == selected_chars.end()) {
                canRead = false;
                break;
            }
        }
        if (canRead) count++;
    }
    maxReadable = max(maxReadable, count);
}

void selectChars(int start, vector<char> &selected_chars) {
    if (selected_chars.size() == K) {
        countReadableWords(selected_chars);
        return;
    }
    for (int i = start; i < unique_chars.size(); i++) {
        selected_chars.push_back(*next(unique_chars.begin(), i));
        selectChars(i + 1, selected_chars);
        selected_chars.pop_back();
    }
}

int main() {
    cin >> N >> K;
    if (K < 5) {
        cout << 0 << endl;
        return 0;
    }
    if (K == 26) {
        cout << N << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word.substr(4, word.size() - 8)); // Remove "anta" and "tica"
        for (char ch : words.back()) {
            if (find(essential.begin(), essential.end(), ch) == essential.end()) {
                unique_chars.insert(ch);
            }
        }
    }

    vector<char> selected_chars(essential.begin(), essential.end());
    if (unique_chars.size() <= K - 5) {
        maxReadable = N;
    } else {
        selectChars(0, selected_chars);
    }

    cout << maxReadable << endl;
    return 0;
}