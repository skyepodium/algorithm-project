#include <iostream>
#include <vector>
#include <algorithm>

#define max_val 1000000001
#define lld long long int
using namespace std;

int n, s, e, result = 0;

struct info{
    int s;
    int e;
};

vector<info> v;

bool cmp(const info &a, const info &b){
    if(a.s == b.s){
        return a.e < b.e;
    }
    return a.s < b.s;
}

int main(){
    scanf("%d", &n);;
    
    for(int i=0; i<n; i++){
        scanf("%d %d", &s, &e);
        v.push_back({s, e});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    
    int start_node = -max_val, end_node = -max_val;
    for(int i=0; i<n; i++){
        info cur = v[i];
        if(cur.s <= end_node){
            end_node = max(end_node, cur.e);
        }
        else{
            result += end_node - start_node;
            start_node = cur.s;
            end_node = cur.e;
        }
    }
    result += end_node - start_node;
    
    printf("%d\n", result);
}
