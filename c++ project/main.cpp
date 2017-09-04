#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    vector<vector<int>> board(4, vector<int>(4,0));
    
    board[0][0] = 0;
    board[0][1] = 1;
    board[0][2] = 1;
    board[0][3] = 1;
    board[1][0] = 1;
    board[1][1] = 1;
    board[1][2] = 1;
    board[1][3] = 1;
    board[2][0] = 1;
    board[2][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][0] = 0;
    board[3][1] = 0;
    board[3][2] = 1;
    board[3][3] = 0;

    int max = 0;
    for(int a=1; a<board.size(); a++){
        for(int b=1; b<board[0].size(); b++){
            if(board[a][b] == 1){
                board[a][b] = min(board[a][b-1], min(board[a-1][b-1], board[a-1][b])) + 1;
            }
            if(board[a][b] > max){
                max = board[a][b];
            }
        }
    }
    if(max == 0){
        
    }
    
    cout<<max*max<<endl;
}

