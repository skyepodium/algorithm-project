#include <iostream>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 선형 탐색
//사용한 자료구조: 1차원 배열

long long int a[10001];

int main(){

    int n;
    cin >> n;

    a[1] = 1;
    for(int i=2; i<=n; i++){
        a[i] = a[i-1] + i;
    }

    long long int up_sum = 0;
    for(int i=1; i<=n; i++){
        up_sum = up_sum + a[i];
    }
    
    long long int down_sum = 0;
    for(int i=n-1; i>=1; i=i-2){
        down_sum = down_sum + a[i];
    }
    
    cout << up_sum + down_sum << endl;
    
}
