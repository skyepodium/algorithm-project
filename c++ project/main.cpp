#include <iostream>
#define max_int 10001

using namespace std;

int n, result, bonus;
char a[max_int];

int main(){
    scanf("%d", &n);
    scanf("%s", a);
    
    for(int i=0; i<n; i++){
        if(a[i] == 'O'){
            result += i + 1 + bonus;
            bonus++;
        }
        else{
            bonus = 0;
        }
    }
    printf("%d\n", result);
}
