#include <iostream>

#define max_int 501
#define max_val 501

using namespace std;

int n, m, first, second, q, a, b;
int d[max_int][max_int];

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i != j) d[i][j] = max_val;
        }
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &first, &second);
        d[first][second] = 1;
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    
    
    int cnt = 0;
    for(int i=1; i<=n; i++){
        bool is_right = true;
        for(int j=1; j<=n; j++){
            if(d[i][j] == max_val && d[j][i] == max_val){
                is_right = false;
                break;
            }
        }
        if(is_right) cnt++;
    }
    
    printf("%d\n", cnt);
}
