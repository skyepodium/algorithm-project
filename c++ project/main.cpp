#include <iostream>
using namespace std;

int d[1001];
int p[10001];

int main(){

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> p[i];
    }

    for(int i=1; i<=n; i++){
        d[i] = p[i];
        for(int j=1; j<i ; j++){
            if(d[i] < d[i-j] + p[j]){
                d[i] = d[i-j] + p[j];
            }
        }
    }

    cout << d[n] <<endl;
}



