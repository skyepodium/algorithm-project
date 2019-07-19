#include <iostream>
#include <queue>
#define max_int 100001
using namespace std;

int n, num, result;

struct cmp{
    bool operator()(const int &a, const int &b){
        return a > b;
    }
};

int main(){
    scanf("%d", &n);
    
    priority_queue<int, vector<int>, cmp> pq;
    
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        pq.push(num);
    }
    
    while(pq.size() >= 2){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int ret = first + second;
        result += ret;
        pq.push(ret);
    }
    printf("%d\n", result);
}
