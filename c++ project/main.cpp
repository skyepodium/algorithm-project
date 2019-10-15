#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define max_int 101
#define max_val 100
using namespace std;

int n, cnt[max_int], num, node, result=max_val;
bool check[max_int];
vector<int> v[max_int], first, second;

void bfs(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(!check[next]){
                check[next] = true;
                q.push(next);
            }
        }
    }
}

void go(int idx, int first_cnt, int second_cnt){
    if(idx == n+1){
        if((int)first.size() != 0 && (int)second.size() != 0){

            for(int i=1; i<=n; i++) check[i] = false;
            
            bfs(first[0]);
            bool flag = true;
            for(int i=0; i<(int)first.size(); i++){
                int c_node = first[i];
                if(!check[c_node]){
                    flag = false;
                    break;
                }
            }
            
            bfs(second[0]);
            for(int i=0; i<(int)second.size(); i++){
                int c_node = second[i];
                if(!check[c_node]){
                    flag = false;
                    break;
                }
            }
              
            if(flag){
                result = min(result, abs(first_cnt - second_cnt));
            }
        }
        return;
    }
    
    first.push_back(idx);
    go(idx + 1, first_cnt + cnt[idx], second_cnt);
    first.pop_back();
    
    second.push_back(idx);
    go(idx + 1, first_cnt, second_cnt + cnt[idx]);
    second.pop_back();
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &cnt[i]);
    }
    
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        for(int j=0; j<num; j++){
            scanf("%d", &node);
            v[i].push_back(node);
        }
    }
    
    go(1, 0, 0);
    
    if(result == max_val) result = -1;
    printf("%d\n", result);
}
