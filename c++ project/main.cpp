#include <vector>
#include <iostream>

using namespace std;

//시간 복잡도: O(n^3logK) (n은 숫자의 개수: 1<=n<=50, k는 숫자의 크기 1<=k<=1000)
//공간 복잡도: O(n)
//사용한 알고리즘: 반복문
//사용한 자료구조: 1차원 배열

bool isPrime(int num){
    bool flag = true;
    for(int i=2; i*i<=num; i++){
        if(num%i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}

int solution(vector<int> nums) {
    int answer = 0;
    int num, size = (int)nums.size();

    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            for(int k=j+1; k<size; k++){
                num = nums[i] + nums[j] + nums[k];
                if(isPrime(num)) answer++;
            }
        }
    }

    return answer;
}