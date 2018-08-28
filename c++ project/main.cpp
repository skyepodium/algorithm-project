#include <iostream>

using namespace std;

//시간 복잡도: O(2^n)
//공간 복잡도: O(n)
//사용한 알고리즘: 백트래킹
//사용한 자료구조: 1차원 배열
//비고: 원래는 0/1Knapsack문제. 단, 20까지는 재귀로 가능


int n;
int l[21];
int j[21];
int result = 0;

void go(int index, int health, int happy){
    
    if(index == n){
        if(health > 0){
            if(happy > result) result = happy;
        }
        return;
    }
    
    go(index+1, health - l[index], happy + j[index]);
    go(index+1, health, happy);
}

int main(){
    

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> l[i];
    }
    
    for(int i=0; i<n; i++){
        cin >> j[i];
    }

    go(0, 100, 0);
    
    cout << result << endl;
}
