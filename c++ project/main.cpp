#include <iostream>
#include <algorithm>

using namespace std;

int d[16][16];

int result = 0;
int n, m;

void cal_sum(int x, int y){
    
    int sum_result = 0;
    for(int i=x; i<x+m; i++){
        for(int j=y; j<y+m; j++){
            sum_result += d[i][j];
        }
    }
    
    result = max(result, sum_result);
}


int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        result = 0;

        cin >> n >> m;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> d[i][j];
            }
        }
        
        for(int i=0; i<= n-m; i++){
            for(int j=0; j<= n-m; j++){
                
                cal_sum(i, j);
                
            }
        }
        
        cout << "#" << test_case <<" " << result << endl;
        
    }
    return 0;
}
