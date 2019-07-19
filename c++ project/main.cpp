#include <iostream>
#include <vector>
#include <algorithm>
#define lld long long int
#define max_int 11
using namespace std;

int n;

struct info{
    lld x, y;
};

info robot[max_int], house[max_int];
vector<int> v;

int ccw(info r, info p, info q){
    lld first = (p.x - r.x) * (q.y - r.y);
    lld second = (p.y - r.y) * (q.x - r.x);
    lld result = first - second;
    
    if(result > 0) return 1;
    else if(result == 0) return 0;
    else return -1;
}

bool operator > (info a, info b){
    if(a.y == b.y) return a.x > b.x;
    else return a.y > b.y;
}

bool operator <= (info a, info b){
    if(a.y == b.y) return a.x <= b.x;
    else return a.y < b.y;
}

bool intersection(info a, info b, info c, info d){
    lld first = ccw(a, b, c) * ccw(a, b, d);
    lld second = ccw(c, d, a) * ccw(c, d, b);
    
    if(first == 0 && second == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        
        return a <= d && c <= b;
    }
    else{
        return first <= 0 && second <= 0;
    }
}


int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &robot[i].x, &robot[i].y);
    }
    
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &house[i].x, &house[i].y);
        v.push_back(i);
    }
    
    do{
        bool flag = true;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j) continue;
                
                info a = robot[i];
                info b = house[v[i-1]];
                info c = robot[j];
                info d = house[v[j-1]];

                bool check_cross = intersection(a, b, c, d);
                if(check_cross){
                    flag = false;
                }
            }

        }
        if(flag){
            for(int i=0; i<v.size(); i++){
                printf("%d\n", v[i]);
            }
            return 0;
        }
        
    }while(next_permutation(v.begin(), v.end()));
}
