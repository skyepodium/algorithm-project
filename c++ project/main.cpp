#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    string name;
    int day, month, year;
    
    vector<pair<int, string>> v;
    
    while(t--){
        cin >> name >> day >> month >> year;
        
        int day_sum = day + month*31 + year*12*31;
        
        v.push_back(pair<int, string>(day_sum, name));
        
    }
    
    sort(v.begin(), v.end());
    
    int size = (int)v.size();
    
    cout << v[size - 1].second << endl;
    cout << v[0].second << endl;
}
