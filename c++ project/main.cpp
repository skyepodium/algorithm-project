#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        
        vector<int> cal;
        for(int i=0; i<4; i++){
            int a;
            cin >> a;
            for(int j=0; j<a; j++){
                cal.push_back(i);
            }
        }
        
        vector<int> num(n);
        for(int i=0; i<n; i++){
            cin >> num[i];
        }
        
        
        int min_result = 100000000;
        int max_result = -100000000;
        
        do{

            int cal_result = num[0];
            for(int i=1; i<n; i++){
                if(cal[i-1] == 0){
                    cal_result = cal_result + num[i];
                }else if(cal[i-1] == 1){
                    cal_result = cal_result - num[i];
                }else if(cal[i-1] == 2){
                    cal_result = cal_result * num[i];
                }else{
                    cal_result = cal_result / num[i];
                }
            }
            
            min_result = min(min_result, cal_result);
            max_result = max(max_result, cal_result);

        }while(next_permutation(cal.begin(), cal.end()));
        
        cout << "#" << test_case << " " << max_result - min_result << endl;
        
        
    }
    return 0;
}
