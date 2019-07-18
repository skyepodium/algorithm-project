#include <iostream>
#include <algorithm>
#include <vector>
#define lld long long int
using namespace std;

int t;
struct info{
    lld x, y;
};

info point[5];

lld cal_dist(info a, info b){
    lld first = (b.x - a.x) * (b.x - a.x);
    lld second = (b.y - a.y) * (b.y - a.y);
    return first + second;
}
vector<lld> v;

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        v.clear();
        
        for(int i=1; i<=4; i++){
            scanf("%lld %lld", &point[i].x, &point[i].y);
        }
        
        for(int i=1; i<=4; i++){
            for(int j=i+1; j<=4; j++){
                if(i==j) continue;
                
                lld dist = cal_dist(point[i], point[j]);
                v.push_back(dist);
            }
        }
        sort(v.begin(), v.end());
        if(v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[4] == v[5]){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    
}
