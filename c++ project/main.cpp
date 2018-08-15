#include <iostream>
#include <vector>

using namespace std;

//시간 복잡도: O(??)
//공간 복잡도: O(8)
//사용한 알고리즘: 그리디 알고리즘
//사용한 자료구조: 1차원 배열

int pay = 0;
int money[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> pay;
        vector<int> v;
        
        //그리디 알고리즘
        //제일 큰것부터, for문 돌면서 갯수를 계산한다.
        for(int i=0; i<8; i++){
            int count = 0;
            while(pay >= money[i]){
                pay = pay - money[i];
                count++;
            }
            v.push_back(count);
        }
        
        cout << "#" << test_case << endl;
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
