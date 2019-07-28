#include <iostream>
#include <queue>
#include <string>
#define max_int 10001
#define mod 10000
using namespace std;

int t, start_node, end_node, p[max_int];
bool check[max_int];
char cmd[max_int];

int d_operator(int num){
    num *= 2;
    if(num > 9999) num %= mod;
    return num;
}

int s_operator(int num){
    num -= 1;
    if(num == -1) num = 9999;
    return num;
}



int l_operator(int num){
    int ret = 0;
    int d1 = num / 1000;
    int d2 = (num - (d1 * 1000)) / 100;
    int d3 = (num - (d1 * 1000) - (d2 * 100)) / 10;
    int d4 = (num - (d1 * 1000) - (d2 * 100) - (d3 * 10));

    ret = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
    
    return ret;
}

int r_operator(int num){
    int ret = 0;
    int d1 = num / 1000;
    int d2 = (num - (d1 * 1000)) / 100;
    int d3 = (num - (d1 * 1000) - (d2 * 100)) / 10;
    int d4 = (num - (d1 * 1000) - (d2 * 100) - (d3 * 10));
    
    ret = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
    
    return ret;
}

void bfs(int start){
    queue<int> q;
    check[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        int next;
        
        // 1. D
        next = d_operator(node);
        if(!check[next]){
            p[next] = node;
            cmd[next] = 'D';
            check[next] = true;
            q.push(next);
        }
        
        // 2. S
        next = s_operator(node);
        if(!check[next]){
            p[next] = node;
            cmd[next] = 'S';
            check[next] = true;
            q.push(next);
        }

        // 3. l
        next = l_operator(node);
        if(!check[next]){
            p[next] = node;
            cmd[next] = 'L';
            check[next] = true;
            q.push(next);
        }

        // 4. r
        next = r_operator(node);
        if(!check[next]){
            p[next] = node;
            cmd[next] = 'R';
            check[next] = true;
            q.push(next);
        }
    }
}

void go(int node){
    if(node == start_node) return;
    int next = p[node];
    go(next);
    printf("%c", cmd[node]);
}

void init(){
    for(int i=0; i<max_int; i++){
        check[i] = false;
        p[i] = 0;
        cmd[i] = 'A';
    }
}

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d", &start_node, &end_node);
        
        init();
        
        bfs(start_node);
        
        go(end_node);
        
        printf("\n");
    }
}
