#include <iostream>
#include <queue>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: BFS
//사용한 자료구조: 1차원 배열

int height = 0;
int start_point = 0, end_point = 0;
int top_dist = 0;
int down_dist = 0;

int d[1000001];
bool check[1000001];

void bfs(int start){
    check[start] = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        int next;
        next = node + top_dist;
        if(check[next] == false && next >0 && next <= height){
            check[next] = true;
            d[next] = d[node] + 1;
            q.push(next);
        }
        
        next = node - down_dist;
        if(check[next] == false && next >0 && next <= height){
            check[next] = true;
            d[next] = d[node] + 1;
            q.push(next);
        }
        
    }
}

int main(){
    
    cin >> height >> start_point >> end_point >> top_dist >> down_dist;
    
    bfs(start_point);
    
    if(start_point == end_point){
        cout << 0 << endl;
    }else{
        if(d[end_point] > 0){
            cout << d[end_point] << endl;
        }else{
            cout << "use the stairs" << endl;
        }
    }
    
}
