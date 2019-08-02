#include <iostream>
#include <cstring>
#define max_int 101
using namespace std;

int len, result;
char first[max_int], second[max_int];

int main(){
    scanf("%s", first);
    scanf("%s", second);
    len = (int)strlen(first);
    
    for(int i=0; i<len; i++){
        
        int f = first[i];
        int s = second[i];
        
        if(f >= 97) f -= 32;
        if(s >= 97) s -= 32;

        if(f > s){
            result = 1;
            break;
        }
        else if(f < s){
            result = -1;
            break;
        }
    }
            
    printf("%d\n", result);
}
