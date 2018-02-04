#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long int a, b, c;


long long int calc (long long int m, long long int n){
    
    if(n == 0){
        return 1%c;
    }else if(n == 1){
        return m%c;
    }else if(n%2 == 0){
        long long int temp = calc(m, n/2)%c;
        return (temp * temp)%c;
    }else{
        return (m * calc(m, n-1))%c;
    }
}

int main(){
    
    cin >> a >> b >> c;
    
    cout << calc(a, b)%c << endl;

}
