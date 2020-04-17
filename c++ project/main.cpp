#include <iostream>

using namespace std;

int n, num;

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        
        if(num & 1) {
            printf("%d\n", num / 2);
        }
        else{
            printf("%d\n", num / 2 - 1);
        }
        
    }
}
