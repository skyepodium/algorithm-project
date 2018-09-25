#include <iostream>

using namespace std;

int t, n, m;

int main(){
    
    for(int i=0; i<10; i++){

        scanf("%d %d %d", &t, &n, &m);
        
        int mul = n;
        for(int i=0; i<m-1; i++){
            n = n*mul;
        }
        
        printf("#%d %d\n", t, n);

    }
}
