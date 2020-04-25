#include <iostream>
#define max_int 201
using namespace  std;

int n, a, b, c, v[max_int][4], result[max_int];

int main(){
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[i][1] = a;
        v[i][2] = b;
        v[i][3] = c;
    }

    for(int j=1; j<=3; j++){
        for(int i=1; i<=n; i++){
            int cur = v[i][j];

            bool isExist = false;
            for(int k=1; k<=n; k++){
                if(i==k) continue;

                if(cur == v[k][j]) isExist = true;
            }

            if(!isExist) result[i] += cur;
        }
    }

    for(int i=1; i<=n; i++){
        printf("%d\n", result[i]);
    }
}