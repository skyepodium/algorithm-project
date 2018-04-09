#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[16][16];

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> d[i][j];
            }
        }
        
        vector<int> v;
        for(int i=0; i<n/2; i++){
            v.push_back(0);
        }

        for(int i=0; i<n/2; i++){
            v.push_back(1);
        }
        
        int result = 20000;
        
        do{
            vector<int> left;
            vector<int> right;
            
            for(int i=0; i<n; i++){
                if(v[i] == 0){
                    left.push_back(i+1);
                }else{
                    right.push_back(i+1);
                }
            }
            
            int left_power = 0;
            for(int i=0; i<left.size(); i++){
                for(int j=i+1; j<left.size(); j++){
                    left_power = left_power + d[left[i]][left[j]] + d[left[j]][left[i]];
                }
            }

            int right_power = 0;
            for(int i=0; i<right.size(); i++){
                for(int j=i+1; j<right.size(); j++){
                    right_power = right_power + d[right[i]][right[j]] + d[right[j]][right[i]];
                }
            }
            
            result = min(result, abs(left_power - right_power));
            
        }while(next_permutation(v.begin(), v.end()));
        
        cout << "#" << test_case <<" "<<result << endl;
        
    }
    return 0;
}
