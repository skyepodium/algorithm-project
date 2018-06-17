#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct info{
    double l;
    int num;
};

bool cmp(const info &a, const info &b){
    
    return a.l < b.l;
}

int main() {
    
    double x, y, r;
    cin >> x >> y >> r;
    
    
    vector<info> v;
    for(int i=0; i<5; i++){
        int a, b;
        cin >> a >> b;
        
        double diff_x = abs(a-x);
        double diff_y = abs(b-y);
        
        double length = sqrt(diff_x*diff_x + diff_y*diff_y);
        v.push_back({length, i+1});
    }
    
    
    sort(v.begin(), v.end(), cmp);
    
    double result_num = v[0].num;
    double result_l = v[0].l;
    
    if(r<result_l) cout << -1 << endl;
    else cout << result_num << endl;
    
}

