#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

#define max_int 1100000
using namespace std;

bool check[max_int];
int n, num, max_size, result;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct info{
    int cnt;
    int num;
    vector<vector<int>> v;
};

queue<info> q;

void bfs() {
    while(!q.empty()){
        info cur = q.front();
        q.pop();
        
        int c_cnt = cur.cnt;
        int c_num = cur.num;
        
        for(int k=0; k<4; k++){
            
            if(k==0){
                
               for(int i=0; i<n; i++){
                   
                   int cur_num = 0;
                   for(int j=n-1; j>=0; j++){
                       if(cur.v[i][j]){
                           
                       }else{
                           
                       }
                   }
                }
                
                
            }
        }
    }
}

int main(){
    
    scanf("%d", &n);
    max_size = n*n-1;
    
    int temp_val = 0;
    int temp_size = max_size;
    vector<vector<int>> main;
    for(int i=1; i<=n; i++){
        vector<int> sub;
        for(int j=1; j<=n; j++){
            scanf("%d", &num);
            sub.push_back(num);
            
            if(num != 0) temp_val += pow(2, temp_size);
            temp_size--;
            
            result = max(result, num);
        }
        main.push_back(sub);
    }
    
    q.push({0, temp_val, main});
    
    bfs();
    
    printf("%d\n", result);
}

