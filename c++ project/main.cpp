#include <string>
#include <vector>
#define max_int 31
using namespace std;

/*
    시간 복잡도: O(n(m+k)) n: 도시의 수, m: 캐시의 크기, k: 도시 이름의 길이
    공간 복잡도: O(m)
    사용한 알고리즘: 반복문(LRU 구현에 사용)    
    사용한 자료구조: 배열 (캐시 저장에 사용)
*/

/*
    대문자를 소문자로 변경하는 함수
    아스키코드 사용
*/
string to_lowercase(string name) {
    string result = name;

    int name_size = (int)result.size();
    for(int i=0; i< name_size; i++){
        /*
            만약 아스키 코드 값이 97보다 작으면 대문자 이기 때문에
            32를 더해서 대문자로 만들어줍니다.
            a - 97
            A - 65
        */
        if(result[i] < 97) result[i] += 32;
    }

    return result;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    // 도시 이름을 저장할 캐시의 자료구조로 배열 생성
    string a[max_int];

    // 현재 캐시가 어느만큼 차있는지 알기 위한 인덱스
    int idx = 1;

    int city_size = (int)cities.size();
    for(int i=0; i < city_size; i++) {
        /*
            대소문자 구분하지 않기 때문에
            도시 이름은 전부 소문자로 변경시켜줍니다.
        */
        string city_name = to_lowercase(cities[i]);

        // cache hit, cache miss 여부를 체크하기 위한 변수 is_exist
        bool is_exist = false;
        // cache hit인 경우 어떤 캐시가 최근에 사용되었는지 체크하기 위한 인덱스
        int start_idx = 1;
        // 캐시 사이즈가 0인 경우 캐시를 검사하지 않는다.
        if(cacheSize != 0) {
            for(int j=1; j<=idx; j++) {
                if(city_name == a[j]) {
                    is_exist = true;
                    // 가장 최근에 사용된 캐시의 인덱스를 저장해줍니다.
                    start_idx = j;
                    break;
                }
            }
        }

        /*
          cache hit 인 경우 += 1
          cache miss 인 경우 += 5
        */
        if(is_exist) answer += 1;
        else  answer += 5;

        // 1) 만약 캐시가 꽉 찼다면
        if(idx == cacheSize) {
            /*
                최근에 사용된 캐시 부터 끝까지 한칸씩 앞으로 밀어줍니다.
                최근에 사용된 인덱스가 없으면 1부터 시작합니다.
            */
            for(int i=start_idx; i < idx; i++) {
                a[i] = a[i+1];
            }
            // 최근에 사용된 캐시는 제일 뒤에 넣어줍니다.
            a[idx] = city_name;
        }
            // 2) 아직 캐시가 비어있다면
        else if(idx < cacheSize){
            // 인덱스를 1증가시키고 도시 이름을 넣어줍니다.
            idx++;
            a[idx] = city_name;
        }
    }

    return answer;
}