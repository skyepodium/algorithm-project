#include <iostream>
#include <cstring>
#define max_int 11
using namespace std;

int n, size, result;
char a[max_int], w[max_int * 2];

int main(){
    scanf("%s", a);
    size = (int)strlen(a);

    scanf("%d", &n);
    
    for(int line=0; line<n; line++){
        scanf("%s", w);
        
        for(int i=0; i<size-1; i++){
            w[10 + i] = w[i];
        }

        bool find = false;
        for(int i=0; i<10 + size; i++){
            if(find) break;
            
            if(w[i] == a[0]){
                bool flag = true;
                for(int j=0; j<size; j++){
                    if(a[j] != w[i+j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    find = true;
                    result++;
                }
            }
        }
    }
    printf("%d\n", result);
}
