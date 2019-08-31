#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct info{
    int type;
    string userId;
};

vector<info> event;
map<string, string> id;

void slice(string word, int type){
    
    int startIdx = 0;
    
    // change
    if(type == 1) startIdx = 7;
    // enter
    else if(type == 2) startIdx = 6;
    // leave
    else startIdx = 6;
    
    int size = (int)word.size();
    
    string temp = "";
    string userId = "";
    string nickName = "";
    
    for(int i=startIdx; i<size; i++){
        if(word[i] == ' '){
            userId = temp;
            temp = "";
        }
        else{
            temp += word[i];
        }
    }
    if(type == 3) userId = temp;
    else nickName = temp;

    
    // 1. change
    if(type == 1){
        id[userId] = nickName;
    }
    // 2. enter
    else if(type == 2){
        if(id.find(userId) == id.end()){
            id.insert(pair<string, string>(userId, nickName));
        }
        else{
            id[userId] = nickName;
        }
        event.push_back({type, userId});
    }
    // 3. leave
    else{
        event.push_back({type, userId});
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(int i=0; i<(int)record.size(); i++){
        string cmd = record[i];
        
        // 1. 변경
        if(cmd[0] == 'C'){
            slice(cmd, 1);
        }
        // 2. 입장
        else if(cmd[0] == 'E'){
            slice(cmd, 2);
        }
        // 3. 퇴장
        else{
            slice(cmd, 3);
        }
    }
    
    for(int i=0; i<(int)event.size(); i++){
        int type = event[i].type;
        string userId = event[i].userId;
        
        if(type == 2){
            answer.push_back(id[userId] + "님이 들어왔습니다.");
        }
        else{
            answer.push_back(id[userId] + "님이 나갔습니다.");
        }
    }

    
    return answer;
}
