#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//시간 복잡도: O(nlogn)
//공간 복잡도: O(n)
//사용한 알고리즘: stl sort
//사용한 자료구조: 구조체, 1차원 벡터

double start_x, start_y;

struct s{
    int dist;
    int cnt;
    string name;
    double x;
    double y;
};


bool cmp(const s &a, const s &b){
    
    if(a.dist > b.dist){
        return false;
        
    }else if(a.dist == b.dist){
        
        if(a.cnt == b.cnt){
            
            return a.name < b.name;
            
        }else{
            return a.cnt > b.cnt;
        }
        
    }else{
        
        return true;
    }
}

int calc_dist(double x, double y){
    
    double dist_x = (abs(x-start_x)/100)*100;
    double dist_y = (abs(y-start_y)/100)*100;
    
    double dist = sqrt(dist_x*dist_x + dist_y*dist_y);
    
    int result = ((int)dist/100) * 100;
    
    return result;
}


int main(int argc, const char *argv[]) {
    
    
    int n;
    cin >> start_x >> start_y >> n;
    
    vector<s> v;
    
    for(int i=0; i<n; i++){
        
        double target_x, target_y;
        string name;
        int coupon_cnt;
        cin >> target_x >> target_y >> name >> coupon_cnt;
        
        int dist = calc_dist(target_x, target_y);
        
        v.push_back( {dist, coupon_cnt, name, target_x, target_y });
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<v.size(); i++){
        
        cout << v[i].x <<" " << v[i].y <<" "<<v[i].name << " "<<v[i].cnt << endl;
        
    }
    
    
    return 0;
}


