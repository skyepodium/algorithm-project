#include <iostream>
#define lld long long int
using namespace std;

int t;
bool result;
struct info{
    lld x, y;
};

lld min_x, min_y, max_x, max_y;
info point[5], result_node, start_node, end_node, a, b, c, d;

bool operator <= (info a, info b){
    if(a.y == b.y) return a.x <= b.x;
    else return a.y < b.y;
}

bool operator > (info a, info b){
    if(a.y == b.y) return a.x > b.x;
    else return a.y > b.y;
}

int ccw(info r, info p, info q){
    lld first =  (p.x - r.x) * (q.y - r.y);
    lld second = (p.y - r.y) * (q.x - r.x);
    lld result = first - second;
    
    if(result > 0) return 1;
    else if(result == 0) return 0;
    else return -1;
}

bool LineInterSection(info a, info b, info c, info d){
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
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        
        result = false;
        
        scanf("%lld %lld", &start_node.x, &start_node.y);
        scanf("%lld %lld", &end_node.x, &end_node.y);
        
        scanf("%lld %lld %lld %lld", &min_x, &min_y, &max_x, &max_y);

        if(min_x > max_x) swap(min_x, max_x);
        if(min_y > max_y) swap(min_y, max_y);

        point[1] = {min_x, min_y};
        point[2] = {max_x, min_y};
        point[3] = {max_x, max_y};
        point[4] = {min_x, max_y};

        for(int i=1; i<=4; i++){
            info first, second;
            first = point[i];
            if(i==4) second = point[1];
            else second = point[i+1];
            
            bool check_intersection = LineInterSection(start_node, end_node, first, second);
            if(check_intersection){
                result = true;
            }
        }
        
        if(!result){
            if(min_x <= start_node.x && start_node.x <= max_x && min_y <= start_node.y && start_node.y <= max_y){
                if(min_x <= end_node.x && end_node.x <= max_x && min_y <= end_node.y && end_node.y <= max_y){
                    result = true;
                }
            }
        }
        
        if(result) printf("T\n");
        else printf("F\n");
    }
}
