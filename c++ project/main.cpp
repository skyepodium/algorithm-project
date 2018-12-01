#include <iostream>

#define max_int 101
using namespace std;

int n, s, m;
int v[max_int];
bool d[max_int][1001];

int main(){
    scanf("%d %d %d", &n, &s, &m);
    
    for(int i=1; i<=n; i++) scanf("%d", &v[i]);
    
    if(s+v[1] <= m) d[1][s+v[1]] = true;
    if(s-v[1] >= 0) d[1][s-v[1]] = true;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<=m; j++){
            
            if(j+v[i] <= m && d[i-1][j+v[i]] != false){
                d[i][j] = d[i-1][j+v[i]];
            }
            if(j-v[i] >= 0 && d[i-1][j-v[i]] != false){
                d[i][j] = d[i-1][j-v[i]];
            }
            
        }
    }
    int result = -1;
    for(int j=m; j>=0; j--){
        if(d[n][j]){
            result = j;
            break;
        }
    }
    printf("%d\n", result);
    
}
