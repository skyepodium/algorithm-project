#include <iostream>

int a[501][501];
int d[501][501][2];


using namespace std;

int main(){
    
    int m, n;
    cin >> m >> n;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }


    d[1][1][0] = 1;
    d[1][1][1] = 1;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            
            if(i==1 && j==1){
                continue;
            }
            
            else if(a[i][j] == 0){
                d[i][j][0] = d[i-1][j][0] + d[i][j-1][1];
                d[i][j][1] = d[i][j-1][1] + d[i-1][j][0];
            }
            
            else if(a[i][j] == 1){
                d[i][j][0] = 0;
                d[i][j][1] = 0;
            }
            
            else{
                d[i][j][0] = d[i-1][j][0];
                d[i][j][1] = d[i][j-1][1];
            }
            
        }
    }
    
    
    
}
