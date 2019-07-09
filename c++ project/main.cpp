#include <iostream>
#include <algorithm>
#define max_int 3001
#define lld long long int
using namespace std;

int n, d[max_int], cnt[max_int], group_cnt, max_cnt;
struct info{
    lld x, y;
};

struct edge{
    info first, second;
};

edge line[max_int];

bool operator > (info &a, info &b){
    if(a.x == b.x) return a.y > b.y;
    else return a.x > b.x;
}

bool operator <= (info &a, info &b){
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

bool check_cross(edge first_line, edge second_line){
    info a = first_line.first;
    info b = first_line.second;
    info c = second_line.first;
    info d = second_line.second;
    
    int first = ccw(a, b, c) * ccw(a, b, d);
    int second = ccw(c, d, a) * ccw(c, d, b);
    
    if(first == 0 && second == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return a <= d && c <= b;
    }else{
        return first <=0 && second <= 0;
    }
}

int find(int node){
    if(node == d[node]) return node;
    else return d[node] = find(d[node]);
}

void init(){
    for(int i=1; i<=n; i++){
        d[i] = i;
        cnt[i] = 1;
    }
}


int main(){
    scanf("%d", &n);
    
    init();
    
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &line[i].first.x, &line[i].first.y);
        scanf("%lld %lld", &line[i].second.x, &line[i].second.y);
    }
    
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(i == j) continue;

            int first_num = find(i);
            int second_num = find(j);
            
            if(first_num != second_num){
                edge first_line = line[i];
                edge second_line = line[j];

                bool check_result = check_cross(first_line, second_line);
                
                if(check_result){
                    if(first_num > second_num) swap(first_num, second_num);
                    d[second_num] = first_num;
                    cnt[first_num] += cnt[second_num];
                    group_cnt++;
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        max_cnt = max(max_cnt, cnt[i]);
    }
    
    printf("%d\n", n-group_cnt);
    printf("%d\n", max_cnt);
}
