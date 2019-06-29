#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define max_int 1001

using namespace std;

int n, m, d[max_int][max_int], p[max_int][max_int];
char a[max_int], b[max_int];

int main(){
    scanf("%s", a);
    n = (int)strlen(a);
    scanf("%s", b);
    m = (int)strlen(b);
    
    // 0 대각선, 1 위, 2 왼쪽
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]){
                d[i][j] = d[i-1][j-1] + 1;
                p[i][j] = 0;
            }
            else{
                if(d[i-1][j] > d[i][j-1]){
                    d[i][j] = d[i-1][j];
                    p[i][j] = 1;
                }else{
                    d[i][j] = d[i][j-1];
                    p[i][j] = 2;
                }
            }
        }
    }

    
    vector<char> result;
    

    
    int x = n;
    int y = m;
    while(true){
        if(x==0 || y==0) break;
        int dir = p[x][y];
        if(dir == 0){
            result.push_back(a[x-1]);
            x--;
            y--;
        }else if(dir == 1){
            x--;
        }else{
            y--;
        }
    }

    printf("%d\n", d[n][m]);
    for(int i=(int)result.size() - 1; i>=0; i--){
        printf("%c", result[i]);
    }
    printf("\n");
}


