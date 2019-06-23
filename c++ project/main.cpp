#include <iostream>

using namespace std;

int a[21], s, e;

int main(){
    for(int i=1; i<=20; i++) a[i] = i;
    
    for(int i=0; i<10; i++){
        scanf("%d %d", &s, &e);
        
        int size = e - s + 1;
        
        for(int i=0; i<size/2; i++){
            int l_idx = s + i;
            int r_idx = s + (size - i - 1);
            
            int temp = a[l_idx];
            a[l_idx] = a[r_idx];
            a[r_idx] = temp;
        }
    }
    
    for(int i=1; i<=20; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
