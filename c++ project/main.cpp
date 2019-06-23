#include <iostream>
#include <cstring>
#define max_int 101
using namespace std;

int size, result;
char w[max_int];

int main(){
    scanf("%s", w);
    
    size = (int)strlen(w);
    
    int cur = 0;
    for(int i=0; i<size; i++){
        if(w[i] != ','){
            cur = cur*10 + (w[i] - '0');
        }else{
            result += cur;
            cur = 0;
        }
        if(i == size-1){
            result += cur;
            cur = 0;
        }
    }
    printf("%d\n", result);
}
