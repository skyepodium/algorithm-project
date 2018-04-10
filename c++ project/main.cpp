#include <iostream>

using namespace std;

int n, s;
int a[21];
int cnt = 0, current_sum = 0;

void dfs(int current){
    
    if(current == n) return;
    
    if(current_sum + a[current] == s) cnt++;
    
    //이번 것 포함시키지 않고 진행
    dfs(current+1);
    
    //이번 것 포함시키고 진행
    current_sum += a[current];
    dfs(current+1);
    
    current_sum -= a[current];
    
}

int main(){
    
    cin >> n >> s;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    dfs(0);
    cout << cnt << endl;
    
}

