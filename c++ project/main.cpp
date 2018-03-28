#include <iostream>
#include <algorithm>

using namespace std;

int d[3][2001][2001];
int a[1001];

int main(){
    
    int t, w;
    cin >> t >> w;
    
    for(int i=1; i<=t; i++){
        cin >> a[i];
    }
    
    int result = 0;
    for(int i=1; i<=t; i++){
        for(int j=0; j<=w; j++){
            if(a[i] == 1){
                
                d[1][i][j] = max(d[1][i-1][j], d[2][i-1][j-1]) + 1;
                d[2][i][j] = max(d[1][i-1][j-1], d[2][i-1][j]);
                

            }else{

                d[1][i][j] = max(d[1][i-1][j], d[2][i-1][j-1]);
                d[2][i][j] = max(d[1][i-1][j-1], d[2][i-1][j]) + 1;
                
            }
            result = max(result, d[1][i][j]);
            result = max(result, d[2][i][j]);

        }
    }
    
    cout << result << endl;

}

