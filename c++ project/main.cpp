#include <iostream>
#include <queue>
#define max_int 201
using namespace std;

int n, k, a[max_int][max_int], s, fx, fy, check[max_int][max_int], result = 0;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

struct info {
    int x, y;
};
queue<info> q;

void bfs() {
    while (!q.empty()) {
        info cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int virus_num = a[x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (check[nx][ny] == -1) {
                check[nx][ny] = check[x][y] + 1;
                a[nx][ny] = virus_num;
                q.push({ nx, ny });
            }
            else {
                if (check[nx][ny] > check[x][y] + 1) {
                    check[nx][ny] = check[x][y] + 1;
                    a[nx][ny] = virus_num;
                    q.push({ nx, ny });
                }
                else if (check[nx][ny] == check[x][y] + 1) {
                    if (a[nx][ny] > virus_num) {
                        check[nx][ny] = check[x][y] + 1;
                        a[nx][ny] = virus_num;
                        q.push({ nx, ny });
                    }
                }
            }
        }
    }
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            check[i][j] = -1;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);

    init();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);

            if (a[i][j] != 0) {
                check[i][j] = 0;
                q.push({ i, j });
            }
        }
    }

    scanf("%d %d %d", &s, &fx, &fy);

    bfs();

    if (check[fx - 1][fy - 1] <= s) {
        result = a[fx-1][fy-1];
    }

    printf("%d\n", result);
}
