#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Inf = 1e9;
int n, m;

void isFB(int N){
	if(N%3==0 && N%5==0) cout<< "FizzBuzz" << endl;
	else if(N%3==0 && N%5!=0) cout << "Fizz" << endl;
	else if(N%3!=0 && N%5==0) cout << "Buzz" << endl;
	else cout << N << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string name;
	int tar = 0, seq = 0;
	for(int i = 0; i < 3; ++i){
		cin >> name;
		if(name == "FizzBuzz" || name == "Fizz" || name == "Buzz") continue;
		else {
			tar = stoi(name);
			seq = i;
		}
	}

	// cout << tar << "  " << seq << endl;
	int res = tar+(3-seq);
	isFB(res);

	
}
