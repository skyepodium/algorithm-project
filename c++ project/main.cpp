#include <iostream>
#include <cstring>
#define max_int 12
using namespace std;

int t;
char a[max_int], b[max_int];
bool result;

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%s", a);
        scanf("%s", b);

        result = true;
        
        if(strlen(a) == strlen(b)){
            for(int i=0; i<strlen(a); i++){
                if(a[i] == 'B'){
                    if(b[i] != 'B'){
                        result = false;
                        break;
                    }
                }else if(a[i] == 'A' || a[i] == 'D' || a[i] == 'O' || a[i] == 'P' || a[i] == 'Q' || a[i] == 'R'){
                    if(b[i] != 'A' && b[i] != 'D' && b[i] != 'O' && b[i] != 'P' && b[i] != 'Q' && b[i] != 'R'){
                        result = false;
                        break;
                    }
                }else{
                    if(b[i] == 'B' || b[i] == 'A' || b[i] == 'D' || b[i] == 'O' || b[i] == 'P' || b[i] == 'Q' || b[i] == 'R'){
                        result = false;
                        break;
                    }
                }
            }
        }
        else{
            result = false;
        }
        
        if(result){
            printf("#%d SAME\n", test_case);
        }
        else{
            printf("#%d DIFF\n", test_case);
        }
    }
}
