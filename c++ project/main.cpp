#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        cout << "#" << test_case <<" ";
        if(c<a){
            cout << a-c << endl;
        }else if(c>b){
            cout << -1 << endl;
        }else{
            cout << 0 << endl;
        }
        
        
        
        
    }
    return 0;
}
