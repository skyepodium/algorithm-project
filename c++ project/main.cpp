#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info{
    int x;
    int y;
};

bool cmp(const info &a, const info &b){
    
    if(a.y == b.y){
        return a.x < b.x;
    }else{
        return a.y < b.y;
    }
}

int main(){
    
    int n;
    cin >> n;
    
    vector<info> v;
    for(int i=0; i<n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<v.size(); i++){
        printf("%d %d\n", v[i].x, v[i].y);
    }
    
}
