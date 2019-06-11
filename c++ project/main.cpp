#include <iostream>
#define max_int 101
using namespace std;

int num, result;
bool check[max_int];
int main(){
    while(true){
        scanf("%d", &num);
        if(num == -1) break;
        for(int i=0; i<max_int; i++){
            check[i] = false;  
        }
        check[num] = true;
        result = 0;
        
        while(true){
            scanf("%d", &num);
            if(num == 0) break;
            check[num] = true;
        }
        for(int i=1; i<=50; i++){
            if(check[i] && check[i*2]){
//                cout << i << endl;
                result++;
            }
        }
        printf("%d\n", result);
    }
}
