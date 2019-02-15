#include <iostream>

#define max_int 501
using namespace std;

int n, m, x1, y1, x2, y2;
int a[max_int][max_int];

int main(){
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    while(m--){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);



        int r1 = 0;
        int r2 = 0;
        int r3 = 0;
        int r4 = 0;

        for(int i=1; i<=x1 - 1; i++){
            for(int j=1; j<=y1 - 1; j++){
                r1 += a[i][j];
            }
        }

        for(int i=1; i<=x1 - 1; i++){
            for(int j=1; j<=y2; j++){
                r2 += a[i][j];
            }
        }

        for(int i=1; i<=x2; i++){
            for(int j=1; j<=y1 - 1; j++){
                r3 += a[i][j];
            }
        }

        for(int i=1; i<=x2; i++){
            for(int j=1; j<=y2; j++){
                r4 += a[i][j];
            }
        }

        printf("%d\n", r4 - r2 - r3 + r1);
    }


}