#include <iostream>

#define max_int 100001
using namespace std;

int t, n, m, num, start_index, end_index;
int a[max_int];
int b[max_int];
int c[max_int];

int main(){
    scanf("%d", &t);

    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d", &n, &m);

        for(int i=1; i<=n; i++){
            scanf("%d", &num);
            a[i] = a[i-1];
            b[i] = b[i-1];
            c[i] = c[i-1];
            if(num == 1) a[i]++;
            else if(num == 2) b[i]++;
            else c[i]++;
        }

        printf("#%d\n", test_case);
        for(int i=0; i<m; i++){
            scanf("%d %d", &start_index, &end_index);
            printf("%d ", a[end_index] - a[start_index-1]);
            printf("%d ", b[end_index] - b[start_index-1]);
            printf("%d\n", c[end_index] - c[start_index-1]);
        }
    }


}