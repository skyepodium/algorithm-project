#include <iostream>

#define max_int 1000001

using namespace std;

int t, n, m, a, b, c;
int d[max_int];

int find(int node){
    
    if(d[node] == node) return node;
    else return d[node] = find(d[node]);
}

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        scanf("%d %d", &n, &m);
        
        for(int i=1; i<=n; i++) d[i] = i;
        
        printf("#%d ", test_case);
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &a, &b, &c);
            
            //합집합
            if(a == 0){
                d[find(b)] = find(c);
            }
            //찾는다.
            else{
                if(find(b) == find(c)){
                    printf("1");
                }
                else{
                    printf("0");
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}

