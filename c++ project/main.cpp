#include <iostream>
#include <algorithm>

#define max_val 100001
#define max_int 1001
using namespace std;

int t, n, num, result;
int a[max_int][max_int];

int main(){

    scanf("%d", &t);
    for(int test_case = 1; test_case<=t; test_case++){
        result = max_val;
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                a[i][j] = max_val;
                scanf("%d", &num);
                if(num == 1) a[i][j] = 1;
                if(i==j) a[i][j] = 0;
            }
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(a[i][j] > a[i][k] + a[k][j]){
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }

        for(int i=1; i<=n; i++){
            int temp = 0;
            for(int j=1; j<=n; j++){
                if(i!=j) temp += a[i][j];
            }
            result = min(result, temp);
        }


        printf("#%d %d\n", test_case, result);
    }
}