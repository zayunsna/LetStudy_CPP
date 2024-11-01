#include <bits/stdc++.h>

using namespace std;

struct Shark {
    int r, c, s, d, z;
    bool alive;
};

int R, C, M;
vector<Shark> sharks;
int grid[100][100]; // Grid for shark position

// 상어 이동 방향
int dr[5] = {0, -1, 1, 0, 0}; // 1: 위, 2: 아래, 3: 오른쪽, 4: 왼쪽
int dc[5] = {0, 0, 0, 1, -1};

// 상어 이동 최적화 함수
void moveSharks() {
    int newGrid[100][100];
    fill(&newGrid[0][0], &newGrid[0][0] + 100 * 100, -1);

    for (int i = 0; i < sharks.size(); ++i) {
        Shark &shark = sharks[i];
        if (!shark.alive) continue; // 이미 잡힌 상어는 무시

        int speed = shark.s;
        int r = shark.r, c = shark.c, d = shark.d;

        // 최적화된 이동: 행 방향 이동(위/아래)인 경우
        if (d == 1 || d == 2) speed %= (R * 2 - 2);
        else speed %= (C * 2 - 2);

        // 이동 처리
        for (int j = 0; j < speed; ++j) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            // 경계를 넘어서면 방향 전환
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                d = (d == 1 || d == 3) ? d + 1 : d - 1;
                nr = r + dr[d];
                nc = c + dc[d];
            }
            r = nr;
            c = nc;
        }

        shark.r = r;
        shark.c = c;
        shark.d = d;

        // 새 위치에 있는 상어 처리
        if (newGrid[r][c] == -1) {
            newGrid[r][c] = i;
        } else {
            int existingShark = newGrid[r][c];
            if (sharks[existingShark].z < shark.z) {
                sharks[existingShark].alive = false;
                newGrid[r][c] = i;
            } else {
                shark.alive = false;
            }
        }
    }

    // 새로운 위치로 갱신
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    cin >> R >> C >> M;
    fill(&grid[0][0], &grid[0][0] + 100 * 100, -1);

    for (int i = 0; i < M; ++i) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        r--; c--; // 0-indexed
        Shark shark = {r, c, s, d, z, true};
        sharks.push_back(shark);
        grid[r][c] = i;
    }

    int totalSize = 0;

    for (int fisher = 0; fisher < C; ++fisher) {
        // 1. 낚시왕이 현재 열에서 가장 가까운 상어를 잡음
        for (int row = 0; row < R; ++row) {
            if (grid[row][fisher] != -1) {
                int sharkIndex = grid[row][fisher];
                totalSize += sharks[sharkIndex].z;
                sharks[sharkIndex].alive = false; // 잡힌 상어
                grid[row][fisher] = -1;
                break;
            }
        }

        // 2. 상어 이동
        moveSharks();
    }

    cout << totalSize << endl;
    return 0;
}