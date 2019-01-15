#include <iostream>
#include <vector>
#include <algorithm>

#define max_int 41
#define lld long long int
using namespace std;

int n, s;
int a[max_int];
vector<int> first, second;
lld cnt = 0;
void go(int idx, int end, int sum, vector<int> &v){

    if(idx == end){
        v.push_back(sum);
        return;
    }

    go(idx+1, end, sum + a[idx], v);
    go(idx+1, end, sum, v);
}


int main(){
    scanf("%d %d", &n, &s);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    go(0, n/2, 0, first);
    go(n/2, n, 0, second);
    sort(second.begin(), second.end());

    for(int i=0; i<(int)first.size(); i++){
        int cur = s - first[i];

        auto lo = lower_bound(second.begin(), second.end(), cur);
        auto up = upper_bound(second.begin(), second.end(), cur);
        cnt += up - lo;
    }
    if(s==0) cnt--;

    printf("%lld\n", cnt);
}