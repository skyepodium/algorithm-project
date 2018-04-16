#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<int> num;

void go(int cnt, vector<int> &pick, int prev){
    
    if(cnt == m){
        
        for(int i=0; i<m; i++){
            printf("%d ", pick[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i=0; i<n; i++){
        
        if(num[i]>prev){
            pick.push_back(num[i]);
            go(cnt+1, pick, num[i]);
            pick.pop_back();
        }
    }
    
}

int main(){
    
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }
    
    sort(num.begin(), num.end());
    
    vector<int> pick;
    go(0, pick, 0);
    
}

