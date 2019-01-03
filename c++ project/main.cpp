#include <iostream>
#include <queue>
using namespace std;

int n, a, b;

int go(int a, int b){
    int ret = 1;
    for(int i=0; i<b; i++){
        ret = ret*a;
    }
    return ret;
}

int main(){
    for(int test_case=1; test_case<=10; test_case++){
        scanf("%d %d %d", &n, &a, &b);
        printf("#%d %d", test_case, go(a, b));
    }

}