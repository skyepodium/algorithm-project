#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v;

    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    
    cout<<v[0]*v[v.size()-1]<<endl;
}

