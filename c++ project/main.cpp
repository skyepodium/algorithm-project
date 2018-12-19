#include <iostream>

using namespace std;

int t, num;
int result = 0;

int main(){
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <=t; test_case++){
        scanf("%d", &num);
        
        if(num>=1000000) result = 5;
        else if(num>=100000) result = 4;
        else if(num>=10000) result = 3;
        else if(num>=1000) result = 2;
        else if(num>=100) result = 1;
        else result = 0;
        
        printf("#%d %d\n", test_case, result);
        
    }
    
}
