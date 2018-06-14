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
        int n, k;
        cin >> n >> k;
        
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        
        sort(v.begin(), v.end());
        
        int result = 0;

        for(int i=n-1; i>n-1-k; i--){
            result = result + v[i];
        }
        
        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}
