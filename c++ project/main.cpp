#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;

int start_time = 2147483647;
int end_time = 0;

int result = 0;

struct info{
    int start_day;
    int end_day;
};

bool cmp(const info &a, const info &b){
    
    if(a.end_day < b.end_day){
        return true;
    }else if(a.end_day == b.end_day){
        
        return a.start_day < b.start_day;
    }else{
        return false;
    }
}

int main(){
    
    cin >> n;
    
    vector<info> plan;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        
        start_time = min(start_time, a);
        end_time = max(end_time, b);
        
        plan.push_back({a, b});
    }
    
    sort(plan.begin(), plan.end(), cmp);
    
     for(int i=0; i<plan.size(); i++){
     cout << plan[i].start_day << " " <<plan[i].end_day<<endl;
     }
    
    
}

