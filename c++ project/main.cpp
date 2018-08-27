#include <iostream>

using namespace std;

int d[10001];

int n, m;
int cnt = 0;

int main(){
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> d[i];
    }
    
    for(int i=0; i<n; i++){
        int result = 0;
        for(int j=i; j<n; j++){
            
            if(result == m){
                cnt++;
                break;
            }else{
                if(result < m){
                    result = result + d[j];
                    if(result == m){
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
    
    cout << cnt << endl;
}
