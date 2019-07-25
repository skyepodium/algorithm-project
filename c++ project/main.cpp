#include <iostream>
#include <algorithm>
#define max_int 101
using namespace std;

int n, a[max_int], temp[max_int], result;

void cal(int start, int end){
    int ret = 0;
    for(int i=1; i<=n; i++){
        temp[i] = a[i];
    }
    for(int i=start; i<=end; i++){
        if(temp[i] == 0) temp[i] = 1;
        else temp[i] = 0;
    }
    for(int i=1; i<=n; i++){
        if(temp[i] == 1) ret++;
    }
    result = max(result, ret);
}

int main(){
    scanf("%d", &n);
    
//    int t = 0;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
       // if(a[i] == 1) t++;
    }
    //result = max(result, t);
    
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            cal(i, j);
        }
    }
    
    printf("%d\n", result);
}
