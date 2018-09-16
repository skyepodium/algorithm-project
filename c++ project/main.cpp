#include <vector>
#define max_int 10000001

using namespace std;

//시간 복잡도: O(nloglogn)
//공간 복잡도: O(n)
//사용한 알고리즘: 에라토스테네스의 체
//사용한 자료구조: 1차원 배열

bool check[max_int];

long long solution(int N) {
    
    //1. 배열 초기화
    for(int i=0; i<=N; i++) check[i] = false;
    
    //2. 에라토스테네스의 체로 소수가 아닌 수를 true로 체크한다.
    for(int i=2; i*i<=N; i++){
        for(int j=i*i; j<=N; j=j+i){
            check[j] = true;
        }
    }
    
    long long answer = 0;
    
    //3. 체크 배열에서 false인 i는 소수이다.
    //answer에 소수를 더해준다.
    for(int i=2; i<=N; i++){
        if(check[i] == false){
            answer = answer + i;
        }
    }
    
    return answer;
}
