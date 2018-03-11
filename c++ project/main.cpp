#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원배열, queue

int dist[1001][1001];
bool check[1001][1001];
int s;

void bfs(int s, int c){
    check[s][c] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(s, c));
    
    while(!q.empty()){
        s = q.front().first;
        c = q.front().second;
        q.pop();
        
        if(check[s][s] == false && s>0){
            check[s][s] = true;
            dist[s][s] = dist[s][c] + 1;
            q.push(make_pair(s, s));
        }
        
        if(s+c<=1000 && check[s+c][c] == false && c>0){
            check[s+c][c] = true;
            dist[s+c][c] = dist[s][c] + 1;
            q.push(make_pair(s+c, c));
        }

        if(s-1 >= 0 && check[s-1][c] == false){
            check[s-1][c] = true;
            dist[s-1][c] = dist[s][c] + 1;
            q.push(make_pair(s-1, c));
        }


    }
    
    
}


int main(){
    
    cin >> s;
    bfs(1, 0);

    int min_day = 1000;
    
    for(int i=0; i<1000; i++){
        if(dist[s][i] > 0){
            min_day = min(min_day, dist[s][i]);
        }
    }
    
    cout << min_day << endl;
}
