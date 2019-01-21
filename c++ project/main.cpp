#include <iostream>

#define max_int 100001
using namespace std;

int n, q, a, b, c;
int d[max_int];

int find(int node){
    if(node == d[node]) return node;
    else return d[node] = find(d[node]);
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++){
        d[i] = i;
    }

    for(int i=0; i<q; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0){// 동맹을 맺는다.
            d[find(b)] = find(c);
        }
        else{ // 동맹인지를 알아본다.
            b = find(b);
            c = find(c);
            if(b == c){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
    }
}