#include <iostream>

using namespace std;

int a[10], b[10], a_result, b_result;

int main(){
    for(int i=0; i<10; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<10; i++){
        scanf("%d", &b[i]);
    }
    for(int i=0; i<10; i++){
        if(a[i] > b[i]) a_result++;
        else if(a[i] < b[i]) b_result++;
    }

    if(a_result > b_result) printf("A\n");
    else if(a_result == b_result) printf("D\n");
    else printf("B\n");
}
