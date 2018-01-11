#include <iostream>

using namespace std;

//시간 복잡도: O(n√n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top Down
//사용한 자료구조: 1차원 배열

int d[100001];

int go(int n){

    if(n < 2){
        return n;
    }

    if(d[n] < n){
        return d[n];
    }
    
    for(int j=1; j*j<=n; j++){
        if(d[n] > go(n-j*j) + 1){
            d[n] = go(n-j*j) + 1;
        }
    }
    
    return d[n];
}


int main(){

    int n;
    cin >> n;
    
    for(int i=0; i<=n; i++){
        d[i] = i;
    }
    
    cout << go(n) << endl;

}

