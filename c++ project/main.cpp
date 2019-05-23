#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
struct info{
    int a;
    int b;
    char c;
};
vector<info> v;

bool cmp(const info &a, const info &b){
    if(a.b == b.b){
        return a.a < b.a;
    }else{
        return a.b < b.b;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<m; i++){
        cout << v[i].c;
    }
    cout << endl;
    
}
