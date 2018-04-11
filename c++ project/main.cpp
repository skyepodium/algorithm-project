#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int n;
int t[100];
int p[100];
int result = 0;

void go(int day, int sum){
    
    if(day >= n){
        
        if(day == n) result = max(result, sum);
        return;
    }
    
    go(day+t[day], sum+p[day]);
    
    go(day+1, sum);
}

int main(){

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t[i] >> p[i];
    }

    go(0, 0);
    cout << result << endl;
}
