#include <iostream>

using namespace std;

long long int count2(long long int num){
    long long int result = 0;
    for(long long int i=2; i<=num; i = i*2){
        result = result + num/i;
    }
    
    return result;
}

long long int count5(long long int num){
    long long int result = 0;
    for(long long int i=5; i<=num; i = i*5){
        result = result + num/i;
    }
    
    return result;
}
int main(){
    
    long long int n, m;
    cin >> n >> m;
    
    cout << min(count2(n) - count2(m) - count2(n-m), count5(n) - count5(m) - count5(n-m)) << endl;
    
}

