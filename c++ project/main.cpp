#include <iostream>
#include <queue>
#include <vector>
#define max_int 10000
using namespace std;

int t, n, mid_num, a[max_int];
vector<int> result;

struct left_cmp{
    bool operator()(const int &a, const int &b){
        return a < b;
    }
};

struct right_cmp{
    bool operator()(const int &a, const int &b){
        return a > b;
    }
};

void init(){
    result.clear();
}

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        
        init();
        
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
        }
        
        mid_num = a[1];
        result.push_back(a[1]);
        
        priority_queue<int, vector<int>, left_cmp> left_q;
        priority_queue<int, vector<int>, right_cmp> right_q;
        
        for(int i=2; i<=n; i++){
            if(a[i] > mid_num){
                right_q.push(a[i]);
            }else if(a[i] < mid_num){
                left_q.push(a[i]);
            }else{
                if(a[i] == a[i+1]){
                    left_q.push(a[i]);
                    right_q.push(a[i+1]);
                    i = i +1;
                }else{
                    left_q.push(a[i]);
                }
            }
            if(i % 2 == 1){
                int left_size = (int)left_q.size();
                int right_size = (int)right_q.size();
               if(left_size  < right_size){
                    left_q.push(mid_num);
                    mid_num = right_q.top();
                    right_q.pop();
                }else if(left_size > right_size){
                    right_q.push(mid_num);
                    mid_num = left_q.top();
                    left_q.pop();
                }
                result.push_back(mid_num);
            }
        }
        
        printf("%d\n", n/2 + 1);
        int cnt = 0;
        for(int i=0; i<(int)result.size(); i++){
            printf("%d ", result[i]);
            cnt++;
            if(cnt == 10){
                printf("\n");
                cnt = 0;
            }
        }
        printf("\n");

    }
}
