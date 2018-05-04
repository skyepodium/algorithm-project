#include <iostream>
#include <vector>

using namespace std;


//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 - Bottom-Up
//사용한 자료구조: 2차원 배열

long long int d[91][2];

int main(){
    
    int n;
    cin >> n;
    
    d[1][0] = 0;
    d[1][1] = 1;
    for(int i=2; i<=n; i++){
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }
    
    cout << d[n][0] + d[n][1] << endl;
}



2. Top-Down(2차원 배열)
시간 복잡도: O(n)
채워야하는 배열의 칸의 수 * 수식의 복잡도 = n*2 = O(2n), 상수상략 O(n)

공간복잡도: O(n)
2*n크기의 배열을 생성하였다. 상수생략, O(n)
#include <iostream>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top-Down
//사용한 자료구조: 2차원 배열

long long int d[91][2];

long long int go(int n, int i){
    
    if(n<2){
        return d[n][i];
    }
    
    if(d[n][i] > 0){
        return d[n][i];
    }
    
    if(i==0) d[i][0] = go(i-1, 0) + go(i-1, 1);
    else d[i][1] = go(i-1, 0);
    
    return d[n][i];
}


int main(){
    
    int n;
    cin >> n;
    
    
    d[1][0] = 0;
    d[1][1] = 1;
    for(int i=2; i<=n; i++){
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }
    
    cout << go(n, 0) + go(n, 1) << endl;
}
