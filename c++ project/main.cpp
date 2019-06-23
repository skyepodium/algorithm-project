#include <iostream>
#include <vector>
#define max_int 1001

using namespace std;

int a, b, cnt[1000001];
vector<int> v;
int main(){
    for(int i=1; i<=max_int; i++){
        for(int j=1; j<=i; j++){
            v.push_back(i);
        }
    }
    scanf("%d %d", &a, &b);
    a--;
    b--;

    int cur = 0;
    for(int i=0; i<v.size(); i++){
        cur += v[i];
        cnt[i] = cur;
    }
    
    printf("%d\n", cnt[b] - cnt[a-1]);
}
