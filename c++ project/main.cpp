#include <iostream>
#define max_int 101
using namespace std;

int t, n;
int a[max_int][max_int];
int d[max_int][max_int];

bool go(int i, int j){
    if(i>=n || j>=n) return 0;

    if(i==n-1 && j==n-1) return 1;

    int &ret = d[i][j];
    if(ret != -1) return ret;
    return ret = (go(i, j+a[i][j]) || go(i + a[i][j], j));

}

int main(){
    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &a[i][j]);
                d[i][j] = -1;
            }
        }

        if(go(0, 0)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

}