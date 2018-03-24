#include <iostream>

using namespace std;

int d[101];
int a[101];

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
            cin >> a[i];
        }
        
        for(int i=0; i<n; i++){
            d[i] = 0;
            for(int j=0; j<i; j++){
                if(a[i] > a[j]){
                    d[i] = d[i] + a[i]-a[j];
                }
            }
        }
        
        for(int i=0; i<n; i++){
            cout << d[i] << endl;
        }

        
        
        
    }
    return 0;
}
