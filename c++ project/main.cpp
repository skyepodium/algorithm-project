#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int sum_result = 0;
        for(int i=0; i<5; i++){
            int num;
            cin >> num;
            if(num <= 40) sum_result += 40;
            else sum_result += num;
        }
        
        cout << "#" << test_case << " " << sum_result/5 << endl;
        
        
    }
    return 0;
}
