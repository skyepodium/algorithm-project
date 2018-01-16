#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101];

long long int result = 0;

void pick(int n, vector<int>& picked, int to_pick){
    
    if(to_pick == 0){
        result = 0;
        for(int i=0; i<7; i++){
            result = result + arr[picked[i]];
        }
        if(result == 100){
            for(int i=0; i<7; i++){
                cout << arr[picked[i]]<<endl;
            }
        }
        
        return;
    }
    
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    
    for(int next = smallest; next < n; ++next){
        picked.push_back(next);
        pick(n, picked, to_pick - 1);
        picked.pop_back();
    }
    
}


int main(){
    
    for(int i=0; i<9; i++){
        cin >> arr[i];
    }
        
    sort(arr, arr+9);
        
    vector<int> picked;
        
    pick(9, picked, 7);
}
