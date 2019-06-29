#include <iostream>
#include <cstring>
#include <algorithm>
#define max_int 1001

using namespace std;

int n, m, d[max_int][max_int];
char a[max_int], b[max_int];

int main(){
    scanf("%s", a);
    n = (int)strlen(a);
    scanf("%s", b);
    m = (int)strlen(b);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]){
                d[i][j] = d[i-1][j-1] + 1;
            }
            else{
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    
    printf("%d\n", d[n][m]);
}


