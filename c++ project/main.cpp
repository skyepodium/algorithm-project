#include <iostream>
#include <vector>
#define max_int 101
using namespace  std;

int n, k, l, x, y, X, a[max_int][max_int], result = 0, len = 1, cx = 1, cy = 1, cdir = 0;
bool apple[max_int][max_int];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

char C, cmd[max_int];

int main(){

    // 1. 입력
    scanf("%d", &n);

    scanf("%d", &k);

    for(int i=1; i<=k; i++){
        scanf("%d %d", &x, &y);
        apple[x][y] = true;
    }

     
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            a[i][j] = -1;
        }
    }

    // 2. 뱀 초기화
    a[1][1] = 0;

    cin >> l;
    for(int i=0; i<=l; i++){
        x = n*n+1;
        if (i < l){
            cin >> X >> C;
        }

        // 3. 반복
        while(result < X){
            result++;
            cx = cx + dx[cdir];
            cy = cy + dy[cdir];

            // 벽에 부딫친경우 종료
            if(cx > n || cx < 1 || cy > n || cy < 1 ) {
                cout << result << endl;
                return 0;
            }

            // 사과 검사
            if(apple[cx][cy]) {
                apple[cx][cy] = false;
                len++;
            }

            // 몸 부딫치는 경우 검사
            if(a[cx][cy] != -1 && result - a[cx][cy] <= len){
                cout << result << endl;
                return 0;
            }

            a[cx][cy] = result;
        }
        // 방향 전환
        if(C == 'L') {
            cdir = (cdir + 3 ) % 4;
        }
        else {
            cdir = (cdir + 1 ) % 4;
        }
    }
    return 0;
}
