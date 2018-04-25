#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top-down
//사용한 자료구조: 2차원 배열

int d[9][9];
bool check[9][9];

void check_sudoku(){
    bool is_possible = true;
    //가로 검사
    for(int i=0; i<9; i++){
        int origin = d[i][0];
        for(int j=1; j<9; j++){
            
            if(d[i][j] == origin){
                is_possible = false;
                break;
            }
        }
    }
    
    //세로검사
    for(int j=0; j<9; j++){
        int origin = d[0][j];
        for(int i=1; i<9; i++){
            
            if(d[i][j] == origin){
                is_possible = false;
                break;
            }
        }
    }

    if(is_possible == true){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << d[i][j] <<" ";
            }
            cout << endl;
        }
    }
    
    
}

void go(int index, vector<pair<int, int>> &v){
    
    if(index == (int)v.size()){
        
        check_sudoku();
        
        return;
    }
    
    for(int i=1; i<=9; i++){
        
        int x = v[index].first;
        int y = v[index].second;
        if(check[x][y] == false){
            
            d[x][y] = i;
            check[x][y] = true;
            go(index+1, v);
            d[x][y] = 0;
            check[x][y] = false;
            
        }
        
    }
    
}

int main(){
    
    //2차원 배열에 입력 받고
    
    vector<pair<int, int>> v;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> d[i][j];
            if(d[i][j] > 0) check[i][j] = true;
            else if(d[i][j] == 0) v.push_back(make_pair(i, j));
        }
    }
    
    go(0, v);
    
}
