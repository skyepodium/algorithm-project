#include <iostream>
#define max_int 2001
using namespace std;

int t, n, a, b, idx;
char result[max_int];
bool check[26];

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d %d", &n, &a, &b);
        
        for(int i=0; i<=n; i++) result[i] = 0;
        
        idx = 0;
        
        for(int i=0; i<a; i++){
            result[i] = idx + 'a';
            if(idx < b-1) idx++;
        }
        
        idx = 0;
        
        for(int i=a; i<n; i++){
            result[i] = idx + 'a';
            if(idx < b-1) idx++;
            else idx=0;
        }
     
        printf("%s\n", result);
    }   
}
