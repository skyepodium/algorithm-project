#include <iostream>
#include <algorithm>
#include <cstring>

#define max_int 11
using namespace std;

int t, n, result;
char a[max_int];
bool d[max_int][max_int];

void init(){
    n = strlen(a);
    result = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            d[i][j] = false;
        }
    }
}

int main(){
    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%s", a);
        init();

        sort(a, a + n);

        for(int i=0; i<n; i++){
            d[i][i] = true;
            result++;
        }

        for(int i=0; i<n-1; i++){
            if(a[i] == a[i+1]){
                d[i][i+1] = true;
                result++;
            }
        }

        for(int k=2; k<n; k++){
            for(int i=0; i<n-k; i++){
                int j=i+k;
                if(a[i] == a[j] && d[i+1][j-1]){
                    d[i][j] = true;
                    result++;
                }
            }
        }

        printf("#%d %d\n", test_case, result);
    }
}