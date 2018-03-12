#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <math.h>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: BFS
//사용한 자료구조: 1차원 배열, 2차원 벡터, 큐

vector<int> a[1000001];
bool exist[1000001];
int check[1000001];
int n, p;

int cal_next(int num){
    
    int result = 0;
    while(num>0){
        result = result + pow(num%10, p);
        num = num/10;
    }
    return result;
}

void dfs(int node, int cnt){
    check[node] = cnt+1;
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        if(check[next] == 0){
            dfs(next, cnt+1);
        }else{
            cout << check[next] - 1 << endl;
            break;
        }
    }
    
}


int main(){

    cin >> n >> p;
    
    exist[n] = true;
    int start = n;
    
    while(true){
        
        int next = cal_next(n);
        if(exist[next] == false){
            exist[next] = true;
            a[n].push_back(next);
        }else{
            a[n].push_back(next);
            break;
        }
        
        n = next;
    }
    
    dfs(start, 0);
    
}
