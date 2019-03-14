#include <iostream>
#include <vector>
#include <algorithm>

#define lld long long int
using namespace std;

int n;

int main(){
    scanf("%d", &n);

    vector<int> a(n), b(n), c(n), d(n);
    for(int i=0; i<n; i++){
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }

    vector<int> first, second;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            first.push_back(a[i]+b[j]);
            second.push_back(c[i]+d[j]);
        }
    }

    sort(second.begin(), second.end());
    lld result = 0;
    for(int i=0; i<first.size(); i++){
        lld num = first[i];
        result += upper_bound(second.begin(), second.end(), -num) - lower_bound(second.begin(), second.end(), -num);
    }
    printf("%lld\n", result);

}