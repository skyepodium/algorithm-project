#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int result = -101;
    do{
        int sum = 0;
        for(int i=0; i<n-1; i++){
            sum = sum + abs(v[i]-v[i+1]);
        }
        result = max(result, sum);
    }while(next_permutation(v.begin(), v.end()));
    
    cout << result << endl;
}
