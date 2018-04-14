#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int d[20][20];

int result;

void do_test(vector<int> &pick, vector<int> &ab){
    
    //테스트를 위한 정보를 가져옴
    int test[20][20];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            test[i][j] = d[i][j];
        }
    }

    //셀의 내용 변경
    for(int i=0; i<pick.size(); i++){
        for(int j=0; j<m; j++){
            test[pick[i]][j] = ab[i];
        }
    }
    
    //테스트 확인
    int for_test = 0;
    for(int j=0; j<m; j++){
        bool is_success = false;
        
        int cnt = 1;
        int current = test[0][j];
        for(int i=1; i<n; i++){
            if(test[i][j] == current){
                cnt++;
            }else{
                current = test[i][j];
                cnt = 1;
            }
            
            if(cnt == k){
                is_success = true;
            }
            
            if(i == n-1){
                if(is_success == true){
                    for_test++;
                }
            }
        }
    }
    
    if(for_test == m){
        result = min(result, (int)pick.size());
    }
    
}

void pick_ab(int index, vector<int> &pick, vector<int> &ab){
    
    if(index == pick.size()){
        if(ab.size() == pick.size()){
            do_test(pick, ab);
        }
        return;
    }
    
    //A를 넣음
    ab.push_back(0);
    pick_ab(index+1, pick, ab);
    ab.pop_back();
    
    //B를 넣음
    ab.push_back(1);
    pick_ab(index+1, pick, ab);
    ab.pop_back();
    
}

void go(int index, vector<int> &pick){
    
    if(index == n){
        
        vector<int> ab;
        pick_ab(0, pick, ab);
        
        return;
    }
    
    // 이번 셀 선택함
    pick.push_back(index);
    go(index+1, pick);
    pick.pop_back();
    
    // 선택하지 않음
    go(index+1, pick);
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> m >> k;
        result = n;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> d[i][j];
            }
        }
        
        vector<int> pick;
        go(0, pick);
        
        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}
