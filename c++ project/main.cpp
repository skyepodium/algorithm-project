#include <iostream>
#include <vector>
#include <queue>

#define max_int 1001
using namespace std;

//시간 복잡도: O(ElogE)
//공간 복잡도: O(V)
//사용한 알고리즘: 프림
//사용한 자료구조: 우선순위큐

int n, m, a, b, c;
bool check[max_int];

struct info{
    int cur;
    int cost;
};
vector<info> v[max_int];

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    
    check[1] = true;
    priority_queue<info, vector<info>, cmp> pq;
    for(int i=0; i<v[1].size(); i++){
        pq.push({v[1][i].cur, v[1][i].cost});
    }
    
    int ans = 0;
    for(int i=0; i<n-1; i++){
        info next;
        while(!pq.empty()){
            next = pq.top();
            pq.pop();
            
            if(check[next.cur] == false){
                break;
            }
        }
        check[next.cur] = true;
        ans += next.cost;
        int x = next.cur;
        for(int i=0; i<v[x].size(); i++) {
            pq.push({v[x][i].cur, v[x][i].cost});
        }
    }

    printf("%d\n", ans);
    
}
