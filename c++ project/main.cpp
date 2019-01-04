#include <iostream>
#include <algorithm>

#define max_int 101
using namespace std;

int n, result, temp;
int a[max_int][max_int];

int main(){
    for(int test_case = 1; test_case<=10; test_case++){
        scanf("%d", &n);
        result = 0;

        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                scanf("%d", &a[i][j]);
            }
        }

        //1. 가로
        for(int i=0; i<100; i++){
            temp = 0;
            for(int j=0; j<100; j++){
                temp += a[i][j];
            }
            result = max(result, temp);
        }

        //2. 세로
        for(int j=0; j<100; j++){
            temp = 0;
            for(int i=0; i<100; i++){
                temp += a[i][j];
            }
            result = max(result, temp);
        }

        //3. 대각선1
        temp = 0;
        for(int i=0; i<100; i++){
            temp += a[i][i];
        }
        result= max(result, temp);

        temp = 0;
        for(int i=0; i<100; i++){
            temp += a[i][100 - 1- i];
        }
        result= max(result, temp);

        printf("#%d %d\n", test_case, result);
    }
}