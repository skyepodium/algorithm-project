#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    vector<int> d;
    for(int i=0; i<4; i++){
        int cnt;
        cin >> cnt;
        for(int j=0; j<cnt; j++){
            d.push_back(i);
        }
    }
    
    long long int max_result = -1000000001;
    long long int min_result = 1000000000;

    do{
        long long int result = v[0];
        for(int i=1; i<v.size(); i++){
            if(d[i-1] == 0){
                result = result + v[i];
            }else if(d[i-1] == 1){
                result = result - v[i];
            }else if(d[i-1] == 2){
                result = result * v[i];
            }else{
                result = result / v[i];
            }
        }
        max_result = max(result, max_result);
        min_result = min(result, min_result);
        
    }while(next_permutation(d.begin(), d.end()));
    
    cout << max_result << endl;
    cout << min_result << endl;
    
}

