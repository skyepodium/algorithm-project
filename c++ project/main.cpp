#include <iostream>

#define max_int 101
using namespace std;

int n, x, y;
bool check[max_int][max_int];
int result = 0;

int main(){
    scanf("%d", &n);

    for(int k=0; k<n; k++){
        scanf("%d %d", &x, &y);
        for(int i=x; i<x+10; i++){
            for(int j=y; j<y+10; j++){
                if(!check[i][j]){
                    check[i][j] = true;
                    result++;
                }
            }
        }
    }
    printf("%d\n", result);

}