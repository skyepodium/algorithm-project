#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool check[9];

void go(int cnt, vector<int> &pick){
    
    if(cnt == m){
        
        for(int i=0; i<m; i++){
            printf("%d ", pick[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i=1; i<=n; i++){
        
        if(check[i] == false){
            check[i] = true;
            pick.push_back(i);
            go(cnt+1, pick);
            check[i] = false;
            pick.pop_back();
        }
        
    }
    
}

int main(){
    
    scanf("%d %d", &n, &m);
    
    vector<int> pick;
    go(0, pick);
    
}

