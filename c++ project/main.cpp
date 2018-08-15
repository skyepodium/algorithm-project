#include <iostream>
#include <string>
#include <vector>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 2중 for문
//사용한 자료구조: 2차원 배열

int n;
char d[7][7];

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> d[i][j];
            }
        }
        
        //90도
        vector<string> v1;
        for(int j=0; j<n; j++){
            string num;
            for(int i=n-1; i>=0; i--){
                num = num + d[i][j];
            }
            v1.push_back(num);
        }
        
        //180도
        vector<string> v2;
        for(int i=n-1; i>=0; i--){
            string num;
            for(int j=n-1; j>=0; j--){
                num = num + d[i][j];
            }
            v2.push_back(num);
        }
        
        //270도
        vector<string> v3;
        for(int j=n-1; j>=0; j--){
            string num;
            for(int i=0; i<n; i++){
                num = num + d[i][j];
            }
            v3.push_back(num);
        }
        
        cout << "#" << test_case << " " << endl;
        for(int i=0; i<v1.size(); i++){
            cout << v1[i] << " ";
            cout << v2[i] << " ";
            cout << v3[i] << endl;
        }
    
    }
    return 0;
}
