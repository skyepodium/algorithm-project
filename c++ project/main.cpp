#include <iostream>
#include <queue>
using namespace std;

int n, num;

int main () {
    scanf("%d", &n);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=1; i<=n*n; i++) {
        scanf("%d", &num);
        
        pq.push(num);
        
        while(pq.size() > n) {
            pq.pop();
        }
    }
    
    printf("%d\n", pq.top());
}
