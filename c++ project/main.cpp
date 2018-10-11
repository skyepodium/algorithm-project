#include <iostream>

#define max_int 21
#define max_val 21000;

using namespace std;

int n;
int d[max_int][max_int];

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &d[i][j]);
        }
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}
