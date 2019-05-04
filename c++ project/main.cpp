#include <iostream>
#include <queue>

#define max_int 51
using namespace std;

int n, m, t, a[max_int][max_int];

int main(){
    scanf("%d %d %d", &n, &m, &t);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
}
