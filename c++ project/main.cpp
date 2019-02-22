#include <iostream>

#define max_int 40001
using namespace std;

int n;
int d[max_int];
int stack[max_int];
int top = 1;
int idx;

int binary_search(int start, int end, int val){

    int ret = 0;
    int mid = 0;

    while(start <= end){
        mid = (start + end) / 2;

        if(stack[mid] < val){
            start = mid + 1;
        }
        else{
            ret = mid;
            end = mid - 1;
        }

    }
    return ret;
}

int main(){
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &d[i]);
    }

    stack[top] = d[1];
    for(int i=2; i<=n; i++){
        if(stack[top] < d[i]){
            top++;
            stack[top] = d[i];
        }
        else{
            idx = binary_search(1, top, d[i]);
            stack[idx] = d[i];
        }
    }

    printf("%d\n", top);
}