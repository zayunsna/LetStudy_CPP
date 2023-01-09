#include "/home/icegpu/HK/HKTool.h"
#include <bits/stdc++.h>
using namespace std;

void old_smartphone_solution(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int arr[1000] = { 0 };
        bool check[1000] = { false };
        bool op[4] = { 0 }; //+ - * /

        int N, O, M, target;
        cin >> N >> O >> M;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            arr[x] = 1; check[x] = true;
        }

        for (int i = 0; i < O; i++) {
            int x; cin >> x; op[x - 1] = true;
        }

        cin >> target;

        for (int i = 1; i < 10; i++)
            if (arr[i])
                for (int j = 0; j < 10; j++)
                    if (arr[j])
                        arr[i * 10 + j] = 2, check[i * 10 + j] = true;

        for (int i = 10; i < 100; i++)
            if (arr[i])
                for (int j = 0; j < 10; j++)
                    if (arr[j])
                        arr[i * 10 + j] = 3, check[i * 10 + j] = true;

        if (arr[target]) {
            cout << "#" << t << " " << arr[target] << '\n';
            continue;
        }

        int r = -1;
        for (int i = 3; i < M; i++) {
            for (int j = 999; j > 0; j--) {
                if (!arr[j] || arr[j] + 2 > i) continue;
                for (int k = 999; k > 0; k--) {
                    if (!check[k] || arr[k] + arr[j] + 1 > i) continue;

                    if (op[0])
                        if (j + k < 1000)
                            if (!arr[j + k])
                                arr[j + k] = arr[j] + arr[k] + 1;

                    if (op[1])
                        if(j - k >= 0)
                            if (!arr[j - k])
                                arr[j - k] = arr[j] + arr[k] + 1;

                    if (op[2])
                        if (j * k < 1000)
                            if (!arr[j * k])
                                arr[j * k] = arr[j] + arr[k] + 1;

                    if (op[3])
                        if (!arr[j / k])
                            arr[j / k] = arr[j] + arr[k] + 1;

                    if (arr[target]) {
                        r = i + 1;
                        break;
                    }
                }
                if (arr[target]) break;
            }
            if (arr[target]) break;
        }

        cout << "#" << t << " " << r << '\n';
    }

    return 0;
}

}
