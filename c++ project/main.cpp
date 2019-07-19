#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define max_int 100001
using namespace std;

int n;

struct info{
    double x, y;
};

info point[max_int], origin;
double result;
int ccw(info r, info p, info q){
    double first = (p.x - r.x) * (q.y - r.y);
    double second = (p.y - r.y) * (q.x - r.x);
    double result = first - second;
    
    if(result > 0) return 1;
    else if(result == 0) return 0;
    else return -1;
}

bool dist(info a, info b){
    double first = (a.x - origin.x) * (a.x - origin.x) + (a.y - origin.y) * (a.y - origin.y);
    double second = (b.x - origin.x) * (b.x - origin.x) + (b.y - origin.y) * (b.y - origin.y);
    return first < second;
}

bool cmp(const info &a, const info &b){
    if(a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
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

double cal_dist(info a, info b){
    double ret =  (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    return sqrt(ret);
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%lf %lf", &point[i].x, &point[i].y);
    }
    
    sort(point + 1, point + 1 + n, cmp);
    origin = point[1];
    sort(point + 2, point + 1 + n, cmp2);
    
    vector<info> v;
    v.push_back(point[1]);
    v.push_back(point[2]);
    
    for(int n_node = 3; n_node <=n; n_node++){
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
    
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(i == j) continue;
            info first = v[i];
            info second = v[j];
            result = max(result, cal_dist(first, second));
        }
    }
    
    printf("%.8lf\n", result);
}
