#include <bits/stdc++.h>
using namespace std; 

void t1(){
	int n = 15;
	int idx = 0;   
	n &= ~(1 << idx);
	cout << "1. idx번째 비트뒤집기 : " << n << "\n";
}
void t2(){
	int n = 5;  //1001
	int idx = 0;  
	n ^= (1 << idx);
	cout << "2. 0은 1로, 1은 0으로 XOR T2 : " << n << "\n";
}
void t3(){
	int n = 6;
	int idx = (n & -n); 
	cout << "3. 최하위 켜져있는 인덱스 T3: " << idx << "\n";
}
void t4(){
	int n = 4;  
	cout << "4. 크기가 n인 모든 집합의 모든 비트 켜기 T4 : " << (1 << n) - 1 << "\n";
}
void t5(){
	int n = 13; // 1101
	int idx = 1;   
	n |= (1 << idx);  
	cout << "5. idx번째 불켜기 T5 : " << n << "\n";
}

void t6(){
	int n = 15; // 1111
	int idx = 1;   
	string a = n & (1 << idx) ? "yes" : "no";
	cout << "6. idx번째 비트가 있는지 확인하기 T6 : " << a << "\n";
}

void test5() {   
	t1();
	t2();
	t3();
	t4();
	t5();
	t6(); 
	exit(0);
}
