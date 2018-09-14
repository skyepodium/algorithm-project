#include <iostream>
#include <algorithm>
#define max_int 500001

using namespace std;

int t, n, m;
char num[max_int];

bool cmp(char &a, char &b){
    return a > b;
}

int main(){
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <=t; test_case++){
        
        scanf("%d %d", &n, &m);
        
        scanf("%s", num);

        sort(num, num+n, cmp);
        
        
        printf("#%d ", test_case);
        for(int i=0; i<n-m; i++){
            printf("%c", num[i]);
        }
        printf("\n");
        
    }
    
    
}
