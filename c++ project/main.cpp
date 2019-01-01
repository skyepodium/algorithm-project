#include <iostream>

#define max_int 1000001

using namespace std;
int num;
bool check[max_int];
void eratos(){
    for(int i=2; i*i<=1000000; i++){
        for(int j=i*i; j<=1000000; j=j+i){
            check[j] = true;
        }
    }
}
int main(){
    eratos();
    while(true){
        scanf("%d", &num);
        if(num == 0) break;

        bool find = false;
        for(int i=2; i<=num/2; i++){
            int a = i;
            int b = num-i;
            if(check[a] == false && check[b] == false){
                printf("%d = %d + %d\n", num, a, b);
                find=true;
                break;
            }
        }
        if(!find) printf("Goldbach's conjecture is wrong.\n");
    }
}