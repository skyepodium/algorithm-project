#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[10][10];
bool check[10][10];
int n, m, c;

int cal_pair(vector<int> profit_array){
    
    int max_profit = 0;
    for(int i=0; i<=m; i++){
        
        vector<int> v;
        for(int j=0; j<i; j++){
            v.push_back(0);
        }
        
        for(int j=0; j<(m-i); j++){
            v.push_back(1);
        }
        
        do{
            
            int profit = 0;
            int sum = 0;
            for(int i=0; i<v.size(); i++){
                if(v[i] == 1){
                    profit = profit + profit_array[i] * profit_array[i];
                    sum = sum + profit_array[i];
                }
            }
            
            if(sum <= c){
                max_profit = max(max_profit, profit);
            }
            
        }while(next_permutation(v.begin(), v.end()));
        
    }
    
    
    return max_profit;
}

int cal_profit(int x, int y){
    
    //첫번째 m개 선택 완료
    vector<int> first_profit;
    for(int i=0; i<m; i++){
        first_profit.push_back(d[x][y+i]);
        check[x][y+i] = true;
    }
    
    int first_max = cal_pair(first_profit);
    
    int total_max = 0;
    int second_max = 0;

    //다른 행 먼저 찾는다.
    vector<int> second_profit;
    for(int i=0; i<n; i++){
        if(x == i) continue;
        for(int j=0; j<=(n-m); j++){
            for(int k=0; k<m; k++){
                second_profit.push_back(d[i][j+k]);
            }
            second_max = cal_pair(second_profit);
            total_max = max(total_max, first_max + second_max);
            second_profit.clear();
        }
    }
    
    //겹치는 행
    for(int j=0; j<n; j++){
        if(check[x][y] != false && check[x][y+m] !=false){
            for(int k=0; k<m; k++){
                second_profit.push_back(d[x][j+k]);
            }
            second_max = cal_pair(second_profit);
            total_max = max(total_max, first_max + second_max);
            second_profit.clear();
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            check[i][j] = false;
        }
    }
    
    return total_max;
}


int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {

        cin >> n >> m >> c;
        
        //지도 입력
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> d[i][j];
            }
        }
        
        //첫번째 선택, 제일 왼쪽 좌표 기준
        int sum_result = 0;
        vector<int> first_array;
        for(int i=0; i<n; i++){
            for(int j=0; j<=(n-m); j++){
                sum_result = max(sum_result, cal_profit(i, j));
            }
        }
        
        cout << "#" << test_case <<" "<< sum_result << endl;
        
    }
    return 0;
}
