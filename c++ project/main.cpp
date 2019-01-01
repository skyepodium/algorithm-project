#include <iostream>

#define max_int 1000001
using namespace std;

int n, m;
bool d[max_int];

void eratos(){
    for(int i=2; i*i<=n; i++){
        for(int j=i*2; j<=n; j=j+i){
            d[j] = true;
        }
    }
}

int main(){
    scanf("%d %d", &m, &n);
    eratos();
    d[1] = true;
    for(int i=m; i<=n; i++){
        if(d[i] == false){
            printf("%d\n", i);
        }
    }
}