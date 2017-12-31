#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top down
//사용한 자료구조: 배열

int d[10001][3];
int a[10001];

int go(int n, int j){

    if(n<2){
        if(j==1){
            return a[1];
        }else{
            return 0;
        }
    }
    
    if(d[n][j] > 0){
        return d[n][j];
    }
    
    d[n][0] = max(go(n-1, 0), max(go(n-1, 1), go(n-1, 2)));
    d[n][1] = go(n-1, 0) + a[n];
    d[n][2] = go(n-1, 1) + a[n];
    
    return d[n][j];
}

int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    d[1][0] = 0;
    d[1][1] = a[1];
    d[1][2] = 0;
    

    int result = 0;
    for(int i=0; i<3; i++){
        result = max(result, go(n, i));
    }
    
    cout << result << endl;
}
