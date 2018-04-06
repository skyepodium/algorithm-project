#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Bottom Up
//사용한 자료구조: 2차원 배열 (동적할당)


int hopscotch(vector<vector<int> > board)
{
    
    int row = (int)board.size();
    int col = (int)board[0].size();
    
    int **d = new int*[row];
    for(int i=0; i<row; i++){
        d[i] = new int[col];
        memset(d[i], 0, sizeof(int)*col);
    }
    
    d[0][0] = board[0][0];
    d[0][1] = board[0][1];
    d[0][2] = board[0][2];
    d[0][3] = board[0][3];

    int answer = 0;
    
    for(int i=1; i<row; i++){
        for(int j=0; j<4; j++){
            
            int max_val = 0;
            for(int k=0; k<4; k++){
                if(j == k) continue;
                max_val = max(max_val, d[i-1][k]);
            }
            d[i][j] = max_val + board[i][j];
            
            if(i==row-1) answer = max(answer, d[i][j]);
            
        }
    }
    
    return answer;
}

int main()
{
    vector<vector<int> > test{{1,2,3,5},{5,6,7,8},{4,3,2,1}};

    cout << hopscotch(test) << endl;
}

