#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
    int w[20][20];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>w[i][j];
        }
    }
    
    vector<int> d(n);
    for(int i=0; i<n; i++){
        d[i] = i;
    }
    
    int ans=2147483647;
    
    do{
        bool ok = true;
        int sum = 0;
        
        for(int i=0; i<n-1; i++){
            if(w[d[i]][d[i+1]] == 0){
                ok = false;
            }else{
                sum = sum + w[d[i]][d[i+1]];
            }
        }
            if(w[d[n-1]][d[0]] != 0 && ok){
                sum = sum + w[d[n-1]][d[0]];
                if(ans > sum){
                    ans = sum;
                }
            }
    }while(next_permutation(d.begin(), d.end()));
    
    cout<<ans<<endl;
}
