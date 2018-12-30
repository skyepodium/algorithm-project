#include <iostream>
#include <algorithm>

#define max_int 100001
using namespace std;

int n;
struct info{
    int x;
    int y;
};
info a[max_int];

bool cmp(const info &a, const info &b){
    if(a.x == b.x){
        return a.y < b.y;
    } else{
        return a.x < b.x;
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a[i].x, &a[i].y);
    }

    sort(a, a+n, cmp);
    for(int i=0; i<n; i++){
        printf("%d %d\n", a[i].x, a[i].y);
    }
}