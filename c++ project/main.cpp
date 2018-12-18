#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int t, result;
int pascal[11][11];
int check[36];
string sdate;
string stime;
int month, day, hour, minute, second;
int start_index, last_index, number_min, upper_cnt;
vector<int> v[36];

int is_char(int num);
int is_number(int num);

int to_int(char first, char second){
    int result = 0;
    result = second - '0';
    if(first != '0') result = result + (first - '0') * 10;
    return result;
}

void dfs(int node, int pick_cnt, int char_cnt, int number_cnt, int duple_cnt){

    if(pick_cnt == 10){
        if(node == last_index){
            if(number_cnt >= number_min){
                if(number_cnt >= number_min && upper_cnt - (duple_cnt/2) >= 0 && char_cnt - duple_cnt>=0){
                    if(duple_cnt>0){
                        result = result + pascal[char_cnt - duple_cnt][upper_cnt - (duple_cnt/2)]*pow(2, duple_cnt/2);
                    }
                    else{
                        result = result + pascal[char_cnt][upper_cnt];
                    }
                }
            }
        }
        return;
    }
    
    for(int i=0; i<(int)v[node].size(); i++){
        int next = v[node][i];
        if(check[next] == 0){
            check[next] = 1;
            dfs(next, pick_cnt+1, char_cnt + is_char(next), number_cnt + is_number(next), duple_cnt);
            check[next] = 0;
        }
        else if(check[next] == 1 && next >= 10){
            check[next] = 2;
            dfs(next, pick_cnt+1, char_cnt + 1, number_cnt, duple_cnt + 2);
            check[next] = 1;
        }

    }
}


void make_pascal();
void make_graph();
void init();
void make_time();

int main(){
    scanf("%d", &t);
    make_graph();
    make_pascal();
    
    for(int test_case = 1; test_case <= t; test_case++){
        //1. 초기화
        init();
        
        //2. 시간을 입력받는다.
        cin >> sdate >> stime;
        
        //3. 시간 정제
        make_time();
        
        //4. 탐색 시작
        check[start_index] = 1;
        dfs(start_index, 1, is_char(start_index), is_number(start_index), 0);
        
        printf("#%d %d\n", test_case, result);
    }
}

void init(){
    result = 0;
    for(int i=0; i<36; i++) check[i] = 0;
    
    month = 0;
    day = 0;
    hour = 0;
    minute = 0;
    second = 0;
    start_index = 0;
    last_index = 0;
    number_min = 0;
    upper_cnt = 0;
}


void make_time(){
    month = to_int(sdate[0], sdate[1]);
    day = to_int(sdate[3], sdate[4]);
    hour = to_int(stime[0], stime[1]);
    minute = to_int(stime[3], stime[4]);
    second = to_int(stime[6], stime[7]);
    
    start_index = (day + second)%36;
    last_index = (month + hour + minute)%36;
    number_min = minute/10;
    upper_cnt = second/10;
}

void make_graph(){
    
    int next;
    for(int node=0; node<=35; node++){
        //1. 상단 왼쪽
        if(node>=29) next = node - 9;
        else next = node - 10;
        if(next>=0 && next<=35 && node >=10) v[node].push_back(next);
        
        //2. 상단 오른쪽
        if(node >= 29) next = node - 8;
        else next = node - 9;
        if(next>=0 && next<=35 && node >= 10 && node != 19) v[node].push_back(next);
        
        //3. 왼쪽
        next = node - 1;
        if(next>=0 && next<=35 && node != 0 && node !=10 && node != 20 && node !=29) v[node].push_back(next);
        
        //4. 오른쪽
        next = node + 1;
        if(next>=0 && next<=35 && node != 9 && node !=19 && node != 28 && node != 35) v[node].push_back(next);
        
        //5. 하단 왼쪽
        if(node>=20) next = node + 8;
        else next = node + 9;
        if(next>=0 && next<=35 && node <=27 && node != 0 && node != 10 && node != 20 && node != 29) v[node].push_back(next);
        
        //6. 하단 오른쪽
        if(node >= 20) next = node + 9;
        else next = node + 10;
        if(next>=0 && next<=35 && node <=26 && node !=19 && node != 28) v[node].push_back(next);
    }
}

void make_pascal(){
    
    for(int i=0; i<=10; i++){
        for(int j=0; j<=10; j++){
            pascal[i][j] = 0;
        }
    }
    
    pascal[0][0] = 1;
    for(int i=1; i<=10; i++){
        for(int j=0; j<=10; j++){
            if(j==0) pascal[i][j] = 1;
            else pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
}

int is_number(int num){
    if(num < 10) return 1;
    else return 0;
}

int is_char(int num){
    if(num < 10) return 0;
    else return 1;
}
