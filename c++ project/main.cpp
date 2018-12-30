#include <iostream>
#include <vector>
#include <algorithm>

#define max_int 500001
using namespace std;

int n, num;
struct info{
    int num;
    int idx;
};
info a[max_int];
bool cmp(const info &a, const info &b){
    return a.num < b.num;
}


int main(){
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        a[i].num = num;
        a[i].idx = i;
    }

    stable_sort(a+1, a+n+1, cmp);

    int result = 0;
    for(int i=1; i<=n; i++){
        result = max(result, a[i].idx - i);
    }
    printf("%d\n", result + 1);

}

