#include <iostream>
#define max_int 100001
using namespace std;

int n, m, q, w, d[max_int], a[max_int], b[max_int], c[max_int];

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &d[i]);
    }
    
    for(int i=1; i<=n; i++){
        a[i] = a[i-1];
        b[i] = b[i-1];
        c[i] = c[i-1];
        if(d[i] == 1) a[i]++;
        else if(d[i] == 2) b[i]++;
        else if(d[i] == 3) c[i]++;
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &q, &w);
        
        int a_num = a[w] - a[q-1];
        int b_num = b[w] - b[q-1];
        int c_num = c[w] - c[q-1];

        printf("%d %d %d\n", a_num, b_num, c_num);
    }
}
