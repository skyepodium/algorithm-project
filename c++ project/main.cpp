#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<int> v;
    for(int i=0; i<n+m; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] <<" ";
    }
    
}

