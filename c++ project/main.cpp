#include <vector>
#include <algorithm>

#define max_int 100001
using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법, Bottom-Up
//사용한 자료구조: 1차원 배열


// d[i]는 i번재 스티커를 때거나 안땟을때 얻을 수 있는 최대값
int d[max_int];

int solution(vector<int> sticker)
{
    int answer, size;
    size = (int)sticker.size();

    // 0. 예외처리 1) 길이가 1 - 첫번째 스티커 반환, 2) 길이가 - 두개 중 큰거 반환
    if(size == 1) return sticker[0];
    else if(size == 2) return max(sticker[0], sticker[1]);
    else{

        // 1. 첫번째 스티커를 땠을때
        d[0] = sticker[0];
        d[1] = sticker[0];

        for(int i=2; i<size - 1; i++){
            d[i] = max(d[i-2] + sticker[i], d[i-1]);
        }
        answer = d[size - 2];

        // d 배열 초기화
        for(int i=0; i<size; i++) d[i] = 0;

        // 2. 첫번째 스티커를 안땠을때
        d[0] = 0;
        d[1] = sticker[1];

        for(int i=2; i<size; i++){
            d[i] = max(d[i-2] + sticker[i], d[i-1]);
        }

        answer = max(answer, d[size - 1]);

        return answer;
    }
}