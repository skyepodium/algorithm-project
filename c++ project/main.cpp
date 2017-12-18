#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<pair<int, int> > v;
    int num;
    
    for(int i=0; i<8; i++){
        cin >> num;
        v.push_back(pair<int, int>(num, i+1));
    }
    sort(v.begin(), v.end());
    
    int sum = 0;
    vector<int> result;
    for(int i=3; i<8; i++){
        sum = sum + v[i].first;
        result.push_back(v[i].second);
    }
    cout << sum <<endl;

    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++){
        cout << result[i] <<" ";
    }
}

