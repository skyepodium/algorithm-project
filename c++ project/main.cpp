#include <iostream>
#include <algorithm>
#include <vector>
#define lld long long int
#define max_int 10001
using namespace std;

int n;

struct info{
    lld x, y;
};

info point[max_int], origin;
lld result;

bool dist(info a, info b){
    lld first = (a.x - origin.x) * (a.x - origin.x) + (a.y - origin.y) + (a.y - origin.y);
    lld second = (b.x - origin.x) * (b.x - origin.x) + (b.y - origin.y) + (b.y - origin.y);
    
    return first < second;
}

int ccw(info r, info p, info q){
    lld first = (p.x - r.x) * (q.y - r.y);
    lld second = (p.y - r.y) * (q.x - r.x);
    lld result = first - second;
    
    if(result > 0) return 1;
    else if(result == 0) return 0;
    else return -1;
}

lld ccw2(info r, info p, info q){
    lld first = (p.x - r.x) * (q.y - r.y);
    lld second = (p.y - r.y) * (q.x - r.x);
    lld result = first - second;
    
    return result;
}

bool cmp(const info &a, const info &b){
    if(a.y == b.y) return a.x > b.x;
    else return a.y > b.y;
}

bool cmp2(const info &a, const info &b){
    int ccw_result = ccw(origin, a, b);
    
    if(ccw_result == 0){
        return dist(a, b);
    }
    else{
        return ccw_result > 0;
    }
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &point[i].x ,&point[i].y);
    }
    
    sort(point + 1, point + 1 + n, cmp);
    origin = point[1];
    sort(point + 2, point + 1 + n, cmp2);

    vector<info> v;
    v.push_back(point[1]);
    v.push_back(point[2]);
    
    for(int n_node = 3; n_node <= n; n_node++){
        while(v.size() >= 2){
            info second = v[v.size() - 1];
            v.pop_back();
            info first = v[v.size() - 1];
            
            info third = point[n_node];
            
            int ccw_result = ccw(first, second, third);
            if(ccw_result > 0){
                v.push_back(second);
                break;
            }
        }
        v.push_back(point[n_node]);
    }
    
    for(int i=1; i<v.size() - 1; i++){
        result += ccw2(v[0], v[i], v[i+1]);
    }
    
    if(result < 0) result *= -1;
    result /= 2;
    
    printf("%lld\n", result / 50);
    
}
