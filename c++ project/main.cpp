#include <iostream>
#include <queue>
using namespace std;

int n, num;

int main(){
    for(int test_case=1; test_case<=10; test_case++){
        scanf("%d", &n);
        queue<int> q;
        for(int i=0; i<8; i++){
            scanf("%d", &num);
            q.push(num);
        }

        int idx = 1;
        while(true){
            int cur = q.front();
            q.pop();
            int temp = cur - idx;
            if(temp < 0) temp = 0;
            q.push(temp);
            if(temp == 0)break;
            idx++;
            if(idx == 6){
                idx = 1;
            }
        }

        printf("#%d ", test_case);
        while(!q.empty()){
            printf("%d ", q.front());
            q.pop();
        }
        printf("\n");
    }

}