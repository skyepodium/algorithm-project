#include <iostream>
#define max_int 1001
using namespace std;

int a, b, c;

int max(int a, int b){
    return a < b ? b : a;
}

int max3(int a, int b, int c){
    return max(max(a, b), c);
}

int main(){
    while(true){
        scanf("%d %d %d", &a, &b, &c);
        if(!a && !b && !c) break;
        
        a *= a;
        b *= b;
        c *= c;
        
        if(a > c) swap(a, c);
        if(b > c) swap(b, c);

        if(c == a+b){
            printf("right\n");
        }else{
            printf("wrong\n");
        }
    }
}
