#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(2^n)
//공간 복잡도: O(n)
//사용한 알고리즘: 재귀함수
//사용한 자료구조: 1차원 배열

int n;
int minus_health[20];
int plus_happy[20];
int result = 0;

void go(int num, int happy, int health){
    
    if(num == n){
        
        if(health > 0){
            result = max(result, happy);
        }
        
        return;
    }

    //인사를 할때
    //num은 index 인사하든 안하든 증가한다.
    //happy는 증가한다. plus_happy[num]만큼
    //health는 감소한다. minus_health[num]만큼
    go(num+1, happy + plus_happy[num], health - minus_health[num]);
    

    //인사를 안할때
    go(num+1, happy, health);
}


int main(){
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> minus_health[i];
    }
    
    for(int i=0; i<n; i++){
        cin >> plus_happy[i];
    }

    go(0, 0, 100);
    
    cout << result << endl;
    
}
