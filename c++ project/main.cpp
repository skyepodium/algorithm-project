#include <iostream>

#define max_int 21
using namespace std;

int n, s;
int cnt = 0;
int sub = 0;
int pick = 0;
int a[max_int];

void go(int index){
    
    if(index == n){
        if(sub == s && pick > 0) cnt++;
        return;
    }
    
    pick += 1;
    sub += a[index];
    go(index + 1);
    pick -= 1;
    sub -= a[index];

    go(index + 1);
}

int main(){
    scanf("%d %d", &n, &s);
    
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    
    go(0);
    printf("%d\n", cnt);
}
