#include <iostream>
#include <algorithm>

#define max_int 1001
using namespace std;

int t, n, m;
int a[max_int];
int b[max_int];
int vote[max_int];

int main(){
    scanf("%d", &t);

    for(int test_case = 1; test_case<=t; test_case++){
        scanf("%d %d", &n, &m);

        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
            vote[i] = 0;
        }

        for(int i=1; i<=m; i++){
            scanf("%d", &b[i]);
        }


        for(int j=1; j<=m; j++){
            int min_idx = n;
            for(int i=1; i<=n; i++){
                if(a[i] <= b[j]){
                    min_idx = min(min_idx, i);
                }
            }
            vote[min_idx]++;
        }

        int max_vote = 0;
        int result = 0;
        for(int i=1; i<=n; i++){
            if(vote[i] > max_vote){
                max_vote = vote[i];
                result = i;
            }
        }

        printf("#%d %d\n", test_case, result);
    }
}