#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, num;

struct cmp{
    bool operator()(const int &a, const int &b){
        if(abs(a) == abs(b)){
            return a > b;
        }
        else{
            return abs(a) > abs(b);
        }
    }
};

int main(){
    scanf("%d", &n);
    
    priority_queue<int, vector<int>, cmp> pq;
    
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        
        if(num == 0){
            if(pq.size() == 0){
                printf("0\n");
            }
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else{
            pq.push(num);
        }
    }
}
