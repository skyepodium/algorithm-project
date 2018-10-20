#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int t;
int d[7];

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        for(int i=0; i<7; i++) scanf("%d", &d[i]);

        set<int> result;
        for(int i=0; i<7; i++){
            for(int j=i+1; j<7; j++){
                for(int k=j+1; k<7; k++){
                    result.insert(d[i]+d[j]+d[k]);
                }
            }
        }
        
        set<int>::iterator iter;
        int cnt = 1;
        for(iter = --result.end(); iter != result.begin(); iter--){
            if(cnt == 5){
                printf("#%d %d\n", test_case, *iter);
            }
            cnt++;
        }
        
    }
    
    return 0;
}

