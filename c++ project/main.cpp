#include <iostream>
#include <algorithm>
#include <stack>
#define max_int 100001
#define lld long long int

using namespace std;

int n;

struct info{
    lld x;
    lld y;
};

info origin, a[max_int];

lld dist(info a, info b){
    lld x = (a.x - b.x);
    lld y = (a.y - b.y);
    return x*x + y*y;
}

int ccw(const info a, info b, info c){
    lld first = (b.x-a.x)*(c.y-a.y);
    lld second = (c.x - a.x)*(b.y- a.y);
    lld temp = first - second;
    
    if(temp > 0){
        return 1;
    }else if(temp == 0){
        return 0;
    }else{
        return -1;
    }
}

bool cmp(const info &a, const info &b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

bool cmp2(const info &a, const info &b){
    lld temp = ccw(origin, a, b);
    if(temp == 0){
        return dist(origin, a) <= dist(origin, b);
    }else{
        return temp > 0;
    }
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &a[i].x, &a[i].y);
    }
    
    sort(a + 1, a + n + 1, cmp);
    origin = a[1];
    sort(a + 1, a + n + 1, cmp2);
    
    int n_node = 3;
    stack<info> s;
    s.push(a[1]);
    s.push(a[2]);
    
    while(n_node <= n){
        while(s.size() >= 2){
            info second = s.top();
            s.pop();
            info first = s.top();
            
            if(ccw(first, second, a[n_node]) > 0){
                s.push(second);
                break;
            }
        }
        s.push(a[n_node]);
        n_node++;
    }
    printf("%d\n", (int)s.size());

}
