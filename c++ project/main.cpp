#include <iostream>
#include <queue>
#include <vector>
#define max_int 1001
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

struct Point {
    int x, y;
};

int n, m, t, v[max_int][max_int], check[max_int][max_int], tomatoCnt, dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0}, res = 0;
queue<Point> q;

void bfs() {
    while (!q.empty()) {
        Point cur = q.front();
        int x = cur.x;
        int y = cur.y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if (check[nx][ny] != 0 || v[nx][ny] != 0) {
                continue;
            }

            check[nx][ny] = check[x][y] + 1;
            res = max(res, check[nx][ny]);
            tomatoCnt--;
            q.push({nx, ny});
        }
    }
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &v[i][j]);
            t = v[i][j];
            if (t == 1) {
                q.push({i, j});
            } else if (t == 0) {
                tomatoCnt++;
            }
        }
    }

    bfs();

    if (tomatoCnt != 0) {
        res = -1;
    }

    printf("%d\n", res);
}