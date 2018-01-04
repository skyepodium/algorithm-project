#include <iostream>
#include <vector>
using namespace std;

int arr[101];

long long int result = 0;

int gcd(int a, int b){
    
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

void pick(int n, vector<int>& picked, int to_pick){

    if(to_pick == 0){
        result += gcd(arr[picked[0]], arr[picked[1]]);
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

    int t;
    cin >> t;
    
    while(t--){
        
        
        int n;
        cin >> n;
        
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        vector<int> picked;

        pick(n, picked, 2);
        cout << result << endl;
        result = 0;
    }

}

