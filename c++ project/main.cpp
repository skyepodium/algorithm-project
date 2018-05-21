#include <iostream>
#include <algorithm>

using namespace std;

int d[51];

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        
        for(int i=0; i<n; i++){
            cin >> d[i];
        }
        
        sort(d, d+n);
        
        
        cout << "#" << test_case << " ";
        for(int i=0; i<n; i++){
            cout << d[i] << " ";
        }
        cout << endl;
        
    }
    return 0;
}
