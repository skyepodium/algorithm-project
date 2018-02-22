#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Bottom-Up
//사용한 자료구조: 1차원 배열

int cnt = 0;

void count_nine(int a){

    while(a>0){
        
        if(a%10 == 9) cnt++;
        a /= 10;
    }
    
}


int main(){
    
    for(int i=1; i<=500; i++){
        
        count_nine(i);
        
    }
    
    cout << cnt << endl;
    
    
}

