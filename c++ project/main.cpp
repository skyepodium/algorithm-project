#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v(10);

int main(){

    int n, k, cnt = 0;
    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i=0; i<v.size(); i++){
        while(k>=v[i]){
            k = k-v[i];
            cnt++;
        }
    }
    
    cout << cnt << endl;
    
}
