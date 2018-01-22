#include <iostream>

using namespace std;

int d[15][15];

int main(){
    
    for(int i=1; i<=14; i++){
        d[0][i] = i;
        d[i][1] = 1;
    }
    
    for(int i=1; i<=14; i++){
        for(int j=2; j<=14; j++){
            
            for(int k=1; k<=j; k++){
                d[i][j] = d[i][j] + d[i-1][k];
            }
            
        }
    }
    
    int t, a, b;
    cin >> t;
    
    while(t--){
        cin >> a >> b;
        cout << d[a][b] << endl;
    }
    
}


