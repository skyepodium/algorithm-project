#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main(){
    
    scanf("%d %d", &n, &m);
    
    vector<int> d;
    for(int i=1; i<=n; i++){
        d.push_back(i);
    }
    
    vector<int> v;
    for(int i=0; i<m; i++){
        v.push_back(1);
    }
    
    for(int i=0; i<n-m; i++){
        v.push_back(0);
    }
    
    do{
        
        for(int i=0; i<n; i++){
            if(v[i] == 1){
                printf("%d ", d[i]);
            }
        }
        printf("\n");
        
    }while(prev_permutation(v.begin(), v.end()));
    
    
}

