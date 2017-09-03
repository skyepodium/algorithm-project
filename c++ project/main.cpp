#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    vector<vector<int>> v(3, vector<int>(2,0));
    
    v[0][0] = 1;
    v[0][1] = 4;
    v[1][0] = 3;
    v[1][1] = 4;
    v[2][0] = 3;
    v[2][1] = 10;

    vector<int> ans;

    
    for(int i=0; i<2; i++){
        int sum=0;
        for(int j=0; j<2; j++){
            if(v[j][i] != v[j+1][i]){
                sum=sum+1;
            }
        }
        if(sum == 2){
            ans.push_back(v[1][i]);
        }else{
            if(v[0][i] == v[1][i]){
                ans.push_back(v[2][i]);
            }else{
                ans.push_back(v[0][i]);
            }
        }
    }

    
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}
