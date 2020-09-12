#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

#define max_int 201
#define max_val 20000001
#define lld long long int

using namespace std;

struct info {
    int cur;
    int cost;
};

vector<info> v[max_int];
int d2[max_int], d[max_int], n_size = 0, result = max_val;


struct cmp {
    bool operator()(const info& a, const info& b) {
        return a.cost > b.cost;
    }
};

void init(){
    for(int i=1; i<=n_size; i++){
        d[i] = max_val;
    }
}

void dijkstra(int start_node) {
    priority_queue<info, vector<info>, cmp> pq;
    d[start_node] = 0;
    pq.push({ start_node, d[start_node] });

    while (!pq.empty()) {
        info cur = pq.top();
        int c_node = cur.cur;
        pq.pop();
        
        if(cur.cost > d[c_node]) continue;

        for (int i = 0; i < v[c_node].size(); i++) {
            info next = v[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;

            if (d[n_node] > d[c_node] + n_cost) {
                d[n_node] = d[c_node] + n_cost;
                pq.push({ n_node, d[n_node] });
            }
        }
    }
}

void init2() {
    for(int i=0; i<=n_size; i++) {
        d2[i] = max_val;
    }
}

void dijkstra2(int start_node) {
    priority_queue<info, vector<info>, cmp> pq;
    d2[start_node] = 0;
    pq.push({ start_node, d2[start_node] });

    while (!pq.empty()) {
        info cur = pq.top();
        int c_node = cur.cur;
        pq.pop();

        if(cur.cost > d2[c_node]) continue;

        
        for (int i = 0; i < v[c_node].size(); i++) {
            info next = v[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;

            if (d2[n_node] > d2[c_node] + n_cost) {
                d2[n_node] = d2[c_node] + n_cost;
                pq.push({ n_node, d2[n_node] });
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    n_size = n;
    init();
    
    for(int i=0; i<fares.size(); i++){
        int t_start = fares[i][0];
        int t_end = fares[i][1];
        int t_cost = fares[i][2];
        
        v[t_start].push_back({t_end, t_cost});
        v[t_end].push_back({t_start, t_cost});
    }

    dijkstra(s);
    result = min(result, d[a] + d[b]);

    for(int i=1; i<=n; i++) {
        if(i!=s){
            init2();
            dijkstra2(i);
            
            int temp_result = d2[a] + d2[b] + d[i];
            
            result = min (result, temp_result);
        }
    }
    
    
    answer = result;
 
    return answer;
}


int main(){
    
    int n = 6;
    int s = 4;
    int a = 6;
    int b = 2;
    
    vector<vector<int>> fares;
    
    vector<int> temp;
    
    temp.push_back(4);
    temp.push_back(1);
    temp.push_back(10);
    
    fares.push_back(temp);
    temp.clear();

    temp.push_back(3);
    temp.push_back(5);
    temp.push_back(24);
    
    fares.push_back(temp);
    temp.clear();

    temp.push_back(5);
    temp.push_back(6);
    temp.push_back(2);
    
    fares.push_back(temp);
    temp.clear();

    temp.push_back(3);
    temp.push_back(1);
    temp.push_back(41);
    
    fares.push_back(temp);
    temp.clear();

    temp.push_back(5);
    temp.push_back(1);
    temp.push_back(24);
    
    fares.push_back(temp);
    temp.clear();

    temp.push_back(4);
    temp.push_back(6);
    temp.push_back(50);
    
    fares.push_back(temp);
    temp.clear();

    temp.push_back(2);
    temp.push_back(4);
    temp.push_back(66);
    
    fares.push_back(temp);
    temp.clear();

    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(22);
    
    fares.push_back(temp);
    temp.clear();

    temp.push_back(1);
    temp.push_back(6);
    temp.push_back(25);
    
    fares.push_back(temp);
    temp.clear();

    int answer = solution(n, s, a, b, fares);

    cout << "answer" << endl;
    cout << answer << endl;
}
