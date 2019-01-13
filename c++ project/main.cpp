#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>

#define max_int 101
using namespace std;

int t, n, start_node;
int pre[max_int];
int in[max_int];



int main(){
    scanf("%d", &t);
    for(int test_case = 1; test_case<=t; test_case++){
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &pre[i]);
        }

        for(int i=0; i<n; i++){
            scanf("%d", &in[i]);
        }
    }

    start_node = pre[0];

}