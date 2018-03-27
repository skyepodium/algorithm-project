#include <iostream>
#include <string>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적계획법 Bottom Up
//사용한 자료구조: 1차원 배열

int d[5001];
int a[5001];
int MOD = 1000000;

int main(){
    
    string number;
    cin >> number;
    
    int number_size = (int)number.size();
    
    for(int i=1; i<=number_size; i++){
        a[i] = number[i-1] - 48;
    }
    
    d[0] = 1;
    if(a[1] != 0) d[1] = 1;
    
    for(int i=2; i<=number_size; i++){
        if(a[i] !=0) d[i] = d[i-1]%MOD;
        
        if(a[i-1]*10 + a[i]>=10 && a[i-1]*10 + a[i] <=26){
            d[i] = (d[i] + d[i-2])%MOD;
            d[i] %= MOD;
        }
    }
    
    cout << d[number_size]%MOD << endl;
    
}

