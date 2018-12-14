#include <iostream>
#include <cstring>
#include <algorithm>

#define max_int 2501
using namespace std;

int n;
char a[max_int];
bool d[max_int][max_int];
int r[max_int];

int main(){
    scanf("%s", a);
    n = (int)strlen(a);
    
    for(int i=0; i<n; i++) d[i][i] = true;
    
    for(int i=0; i<n-1; i++){
        if(a[i] == a[i+1]) d[i][i+1] = true;
    }
    
    for(int k=2; k<n; k++){
        for(int i=0; i<n-k; i++){
            int j = i+k;
            if(a[i] == a[j] && d[i+1][j-1]){
                d[i][j] = true;
            }
        }
    }
    
    
    r[0] = 1;
    for(int i=0; i<n; i++){
        r[i] = n;
        for(int j=0; j<=i; j++){
            if(d[j][i] == true){
                r[i] = min(r[i], r[j-1] + 1);
            }
        }
    }
    
    printf("%d\n", r[n-1]);
    
}
