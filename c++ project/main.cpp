#include <iostream>
#define max_int 10001
#define max_val 1000000001
#define lld long long int

using namespace std;

int n;

struct info{
    lld x, y;
};

info point[max_int], terror[4], start_point, end_point;

bool operator > (info a, info b){
    if(a.x == b.x) return a.y > b.y;
    else return a.x > b.x;
}

bool operator <= (info a, info b){
    if(a.x == b.x) return a.y <= b.y;
    else return a.x < b.x;
}

int ccw(info r, info p, info q){
    lld first = (p.x - r.x) * (q.y - r.y);
    lld second = (p.y - r.y) * (q.x - r.x);
    lld result = first - second;
    if(result > 0) return 1;
    else if(result == 0) return 0;
    else return -1;
}

bool check_cross(info a, info b, info c, info d){
    
    int first = ccw(a, b, c) * ccw(a, b, d);
    int second = ccw(c, d, a) * ccw(c, d, b);
    
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
        scanf("%lld %lld", &point[i].x, &point[i].y);
    }
    
    for(int i=1; i<=3; i++){
        scanf("%lld %lld", &terror[i].x, &terror[i].y);
    }
    
    if (n >= 3) {
        for(int i=1; i<=3; i++){
            start_point = terror[i];
            end_point.x = max_val;
            end_point.y = terror[i].y + 1;
            
            bool find = false;
            int cnt = 0;
            for(int j=1; j<=n; j++){
                info first = point[j];
                info second = point[j+1];
                if(j == n) second = point[1];
                
                if(start_point.x == first.x && start_point.y == first.y){
                    printf("1\n");
                    find = true;
                    break;
                }else if(start_point.x == second.x && start_point.y == second.y){
                    printf("1\n");
                    find = true;
                    break;
                }
                
                bool check_result = check_cross(start_point, end_point, first, second);
                if(check_result){
                    cnt++;
                }
            }
            if(find) continue;
            if(cnt % 2 == 0) printf("%d\n", 0);
            else printf("%d\n", 1);
        }
    }
    else{
        for(int i=1; i<=n; i++){
            printf("0\n");
        }
    }
}
