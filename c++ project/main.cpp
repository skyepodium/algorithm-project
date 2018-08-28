#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info{
    int num;
    int g;
    int s;
    int b;
    int grade;
};

bool cmp(const info &a, const info &b){

    if(a.g == b.g){
        
        if(a.s == b.s){
            
            return a.b > b.b;
        }
        else{
            return a.s > b.s;
        }
        
    }else{
        return a.g > b.g;
    }
}

int main(){
    
    int n, k;
    cin >> n >> k;
    
    vector<info> v;
    for(int i=0; i<n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back( { a, b, c, d, 0});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    v[0].grade = 1;
    int diff = 0;
    for(int i=1; i<v.size(); i++){
        if(v[i].g == v[i-1].g && v[i].s == v[i-1].s && v[i].b == v[i-1].b){
            v[i].grade = v[i-1].grade;
            diff++;
        }else{
            v[i].grade = v[i-1].grade + 1 + diff;
            diff = 0;
        }
    }
    
    for(int i=0; i<v.size(); i++){
        if(v[i].num == k){
            cout << v[i].grade << endl;
            break;
        }
    }
}
