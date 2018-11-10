#include <iostream>

using namespace std;

//시간 복잡도: O(nt)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법, Top-Down
//사용한 자료구조: 1차원 배열

int t, n;
int d[12];

int go(int i){
    
    if(i==0) return 1;
    
    if(d[i] > 0) return d[i];
    
    for(int j=1; j<=3; j++){
        if(i-j >= 0) d[i] += go(i-j);
    }

    return d[i];
}

int main(){
    scanf("%d", &t);
    
    while(t--){
        for(int i=0; i<12; i++) d[i] = 0;
        
        scanf("%d", &n);

        printf("%d\n", go(n));
    }
}
