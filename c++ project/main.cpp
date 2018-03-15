#include <iostream>
#include <algorithm>

using namespace std;

double d[10001];
double a[10001];

int main(){

    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    d[0] = a[0];
    for(int i=1; i<n; i++){
        d[i] = max(d[i-1]*a[i], a[i]);
    }
    
    printf("%.3f\n", *max_element(d , d+n));
}

