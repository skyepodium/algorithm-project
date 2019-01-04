#include <iostream>
#include <algorithm>

#define max_int 101
using namespace std;

int n, result;
char a[8][8];


int main(){
    for(int test_case = 1; test_case<=10; test_case++){
        scanf("%d", &n);
        result = 0;

        for(int i=0; i<8; i++){
            scanf("%s", a[i]);
        }

        //1. 가로
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(j+n <= 8){
                    bool isPal = true;
                    for(int k=0; k<n/2; k++){
                        if(a[i][j+k] != a[i][j+(n-1-k)]){
                            isPal = false;
                            break;
                            //1 - 4
                            //2 - 3
                        }
                    }
                    if(isPal) result++;
                }
            }
        }

        //2. 세로
        for(int j=0; j<8; j++){
            for(int i=0; i<8; i++){
                if(i+n <= 8){
                    bool isPal = true;
                    for(int k=0; k<n/2; k++){
                        if(a[i+k][j] != a[i+(n-1-k)][j]){
                            isPal = false;
                            break;
                        }
                    }
                    if(isPal) result++;
                }
            }
        }


        printf("#%d %d\n", test_case, result);
    }
}