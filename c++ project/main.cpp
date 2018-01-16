#include <iostream>

using namespace std;

//시간 복잡도: O(ESM)
//공간 복잡도: 0
//사용한 알고리즘: Brute Force Search
//사용한 자료구조: 없음

int main() {
    
    int E, S, M;
    cin >> E >> S >> M;
    
    int e=1, s=1, m=1;
    
    for(int i=1; ; i++){
        
        if(e == E && s == S && m == M){
            cout << i <<endl;
            break;
        }
        
        e++;
        s++;
        m++;
        
        if(e == 16){
            e = 1;
        }
        
        if(s == 29){
            s = 1;
        }
        
        if(m == 20){
            m = 1;
        }
        
    }
}



