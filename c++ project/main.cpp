#include <iostream>
#include <algorithm>

using namespace std;


int n;
int a[21];
int d[21];

int result = 0;

void go(int num, int happy, int health){
    
    if(num == n){
        
        if(health > 0) result = max(result, happy);
        return;
    }
    
    go(num+1, happy+d[num], health - a[num]);
    
    go(num+1, happy, health);
    
}

int main(){
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    for(int i=0; i<n; i++){
        cin >> d[i];
    }
    
    go(0, 0, 100);

    cout << result << endl;
}
