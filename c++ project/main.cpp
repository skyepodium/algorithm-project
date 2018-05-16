#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int a, b;
        cin >> a >> b;
        
        cout << "#" << test_case << " " << a/b << " " << a%b << endl;
        
        
        
        
    }
    return 0;
}
