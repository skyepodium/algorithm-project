#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int d[10];

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        float result = 0;
        for(int i=0; i<10; i++){
            cin >> d[i];
            result = result + d[i];
        }
        
        sort(d, d+10);
        
        result = result - d[0] - d[9];
        result = result/8;
        result = floor(result+0.5);
        cout << "#" <<test_case << " " << result << endl;
        
        
    }
    return 0;
}
