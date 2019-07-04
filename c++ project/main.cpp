#include <iostream>
#include <algorithm>
#include <stack>
#define lld long long int
#define max_int 100001
using namespace std;

int n;
struct info{
    lld x, y;
};
info a[max_int], origin;

bool dist(info a, info b){
    lld first = (a.x - origin.x) * (a.x - origin.x) + (a.y - origin.y) * (a.y - origin.y);
    lld second = (b.x - origin.x) * (b.x - origin.x) + (b.y - origin.y) * (b.y - origin.y);
    return first < second;
}

lld ccw(info a, info b){
    return a.x*b.y - a.y*b.x;
}

lld ccw(info a, info b, info c){
    lld first = a.x*b.y + b.x*c.y+ c.x*a.y;
    lld second = b.x*a.y + c.x*b.y + a.x*c.y;
    lld result = first - second;
    return result;
}

bool cmp(const info &a, const info &b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

bool cmp2(const info &a, const info &b){
    lld temp = ccw(a, b);
    if(temp == 0){
        return dist(a, b);
    }
    else if(temp > 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &a[i].x, &a[i].y);
    }
    
    sort(a + 1, a + 1 + n, cmp);
    origin = a[1];
    for(int i=1; i<=n; i++){
        a[i].x -= origin.x;
        a[i].y -= origin.y;
    }
    sort(a + 2, a + 1 + n, cmp2);
    
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
