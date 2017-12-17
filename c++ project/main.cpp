#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<int> v;
    while(n--){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    int size = (int)v.size();
    int sum = 0;
    
    if(v[0] == 1){
        sum = sum + 1;
    }
    for(int i=1; i<size; i++){
        
        if(v[i] > 0 && v[i-1] > 0){
            v[i] = v[i-1] + 1;
        }

        if(v[i] > 0){
            sum = sum + v[i];
        }

    }
    cout << sum << endl;
}
