#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int a[4] = {2, 1, 3, 2};
int location = 2;
struct info{
    int idx;
    int cost;
};

struct cmp{
    bool operator()(const info  &a, const info &b){
        return a.cost < b.cost;
    }
};

int main(){
    queue<info> q;
    priority_queue<info, vector<info>, cmp> pq;

    for(int i=0; i<4; i++){
        q.push({i, a[i]});
        pq.push({i, a[i]});
    }

    int cnt = 1;
    while(!q.empty()){
        info cur = q.front();
        q.pop();
        int max_val = pq.top().cost;
        if(cur.cost == max_val){
            if(cur.idx == location){
                printf("%d\n", cnt);
                break;
            }else{
                pq.pop();
                cnt++;
            }
        }
        else{
            q.push(cur);
        }
    }
}
