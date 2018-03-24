#include <iostream>
#include <vector>

int v[1000001];

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
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        
        int current = v[n-1];
        long long int result = 0;
        for(int j=n-1; j>=0; j--){
            if(current > v[j]){
                result = result + (current - v[j]);
            }else{
                current = v[j];
            }
        }
        
        cout <<"#"<<test_case<<" "<<result<<endl;
        
        
    }
    return 0;
}
