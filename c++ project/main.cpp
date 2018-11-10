#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(nk)
//공간 복잡도: O(k)
//사용한 알고리즘: 동적 계획법, Bottom-Up
//사용한 자료구조: 1차원 배열

int n, k;
int a[101];
int d[10001];

int main(){
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int i=0; i<=k; i++){
        d[i] = 10001;
    }
    
    d[0] = 0;
    for(int i=0; i<=k; i++){
        for(int j=0; j<n; j++){
            if(i-a[j] >= 0){
                d[i] = min(d[i], d[i-a[j]]+1);
            }
        }
    }

    
    if(d[k] == 10001) d[k] = -1;
    
    printf("%d\n", d[k]);
}
