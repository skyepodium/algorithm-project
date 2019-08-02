#include <iostream>
#define max_int 1001
using namespace std;

int n, a[max_int], result;

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    for(int i=2; i<=n; i++){
        int num = a[i];
        bool is_min = true;
        bool is_max = true;
        for(int j=1; j<i; j++){
            if(num > a[j]) is_max = false;
            else if(num < a[j]) is_min = false;
            else{
                is_max = false;
                is_min = false;
            }
        }
        
        if(is_min) result++;
        if(is_max) result++;
    }
    printf("%d\n", result);

}
