#include<iostream>

#define max_int 101
using namespace std;

int t, n, max_up, max_down;
int a[max_int];

int main(){
    scanf("%d", &t);

    for(int test_case = 1; test_case<=t; test_case++){
        scanf("%d", &n);
        max_up = 0;
        max_down = 0;

        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        int cur = a[0];
        for(int i=1; i<n; i++){
            if(a[i] > cur){
                max_up = max(max_up, a[i]-cur);
            }
            else{
                max_down = max(max_down, cur-a[i]);
            }
            cur = a[i];
        }
        printf("#%d %d %d\n", test_case, max_up, max_down);
    }
}