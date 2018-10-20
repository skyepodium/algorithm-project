#include <iostream>
#include <algorithm>

#define max_int 1001
using namespace std;

int n;
int d[max_int];
int max_score = 0;
int min_score = 1001;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &d[i]);
        max_score = max(max_score, d[i]);
        min_score = min(min_score, d[i]);
    }
    printf("%d\n", max_score - min_score);
}
