#include <iostream>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(1)
//사용한 알고리즘: 거품 정렬(bubble sort)
//사용한 자료구조: 없음

int main(){
    
    int d[10] = {3, 4, 10, 1, 2, 9, 6, 5, 7, 8};
    
    for(int i=0; i<10; i++){
        
        for(int j=1; j<10 - i; j++){
            if(d[j] < d[j-1]){

                int temp;
                temp = d[j-1];
                d[j-1] = d[j];
                d[j] = temp;
                
            }
        }
    }
    
    for(int i=0; i<10; i++){
        cout << d[i] << " ";
    }
    cout << endl;
    
}

