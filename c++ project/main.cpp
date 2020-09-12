#include <string>
#include <vector>
#include <iostream>
#define max_int 100002
using namespace std;

int db[4][3][3][3][max_int], first, second, third, fourth, fifth, stage;

string cur_val = "";

void cal_val(){
    if(stage == 0) {
        if(cur_val[0] == 'c') {
            first = 1;
        } else if(cur_val[0] == 'j') {
            first = 2;
        } else if(cur_val[0] == 'p') {
            first = 3;
        }
    }
    
    if(stage == 1) {
        if(cur_val[0] == 'b') {
            second = 1;
        } else if(cur_val[0] == 'f') {
            second = 2;
        }
    }

    if(stage == 2) {
        if(cur_val[0] == 'j') {
            third = 1;
        } else if(cur_val[0] == 's') {
            third = 2;
        }
    }

    if(stage == 3) {
        if(cur_val[0] == 'c') {
            fourth = 1;
        } else if(cur_val[0] == 'p') {
            fourth = 2;
        }
    }

    if(stage == 4) {
        int num = 0;
        
        int cur_val_size = (int)cur_val.size();
        
        for(int i=0; i<cur_val_size; i++) {
            num = num * 10 + (cur_val[i] - 48);
        }
        fifth = num;
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    int info_size =(int)info.size();
    for(int i=0; i<info_size; i++) {

        cur_val = "";
        first = 0;
        second = 0;
        third = 0;
        fourth = 0;
        fifth = 0;
        stage= 0;
        
        int info_val_size = (int)info[i].size();
        for(int j=0; j<info_val_size; j++) {
            char cur = info[i][j];
                
            if(cur == 32 || j == info_val_size - 1){
                if(j == info_val_size - 1) {
                    cur_val += cur;
                }
                
                cal_val();
                
                if(j == info_val_size - 1) {
                    db[first][second][third][fourth][fifth] += 1;

                    db[0][0][0][0][0] += 1;
                    
                    db[0][second][third][fourth][fifth] += 1;
                    db[first][0][third][fourth][fifth] += 1;
                    db[first][second][0][fourth][fifth] += 1;
                    db[first][second][third][0][fifth] += 1;
                    db[first][second][third][fourth][0] += 1;

                    db[0][0][third][fourth][fifth] += 1;
                    db[0][second][0][fourth][fifth] += 1;
                    db[0][second][third][0][fifth] += 1;
                    db[0][second][third][fourth][0] += 1;
                    db[first][0][0][fourth][fifth] += 1;
                    db[first][0][third][0][fifth] += 1;
                    db[first][0][third][fourth][0] += 1;
                    db[first][second][0][0][fifth] += 1;
                    db[first][second][0][fourth][0] += 1;
                    db[first][second][third][0][0] += 1;

                    db[0][0][0][fourth][fifth] += 1;
                    db[0][0][third][0][fifth] += 1;
                    db[0][0][third][fourth][0] += 1;
                    db[0][second][0][0][fifth] += 1;
                    db[0][second][0][fourth][0] += 1;
                    db[0][second][third][0][0] += 1;
                    db[first][0][0][0][fifth] += 1;
                    db[first][0][0][fourth][0] += 1;
                    db[first][0][third][0][0] += 1;
                    db[first][second][0][0][0] += 1;
                    
                    db[first][0][0][0][0] += 1;
                    db[0][second][0][0][0] += 1;
                    db[0][0][third][0][0] += 1;
                    db[0][0][0][fourth][0] += 1;
                    db[0][0][0][0][fifth] += 1;
                }
                
                cur_val = "";
                stage += 1;
            }else{
                cur_val += cur;
            }
        }
    }
    
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    for(int m=100000; m>=1; m--){
                        db[i][j][k][l][m] += db[i][j][k][l][m+1];
                    }
                }
            }
        }
    }
    
    
    int query_size =(int)query.size();
    for(int i=0; i<query_size; i++) {

        cur_val = "";
        first = 0;
        second = 0;
        third = 0;
        fourth = 0;
        fifth = 0;
        stage= 0;
        
        int query_val_size = (int)query[i].size();
        for(int j=0; j<query_val_size; j++) {
            char cur = query[i][j];
                
            if(cur == 32 || j == query_val_size - 1){
                if(j == query_val_size - 1) {
                    cur_val += cur;
                }
                cal_val();
                
                if(j == query_val_size - 1) {
                    int result = db[first][second][third][fourth][fifth];
                    answer.push_back(result);
                }
                
                if(cur_val[0] != 'a') {
                    stage += 1;
                }
                cur_val = "";
            }else{
                cur_val += cur;
            }
        }
    }

    return answer;
}
