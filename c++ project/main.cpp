#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<int> num;
bool check[10];

void go(int cnt, vector<int> &pick){
    
    if(cnt == m){
        
        for(int i=0; i<m; i++){
            printf("%d ", pick[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i=0; i<n; i++){
        
        if(check[i] == false){
            check[i] = true;
            pick.push_back(num[i]);
            go(cnt+1, pick);
            check[i] = false;
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
    go(0, pick);
    
}

