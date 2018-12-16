#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, cnt, result;
vector<char> pick;
char alpha_lo[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
char alpha_up[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
bool check[36];
string sdate;
string stime;
int month, day, hour, minute, second;
int start_index, last_index, number_min, upper_num;

vector<int> v[36];

int to_int(char first, char second){
    int result = 0;
    result = second - '0';
    if(first != '0') result = result + (first - '0') * 10;
    return result;
}

void dfs(int node){
    if(cnt == 10){
        if(node == last_index){
            int number_cnt = 0;
            for(int i=0; i<10; i++){
                if(pick[i] < 10) number_cnt++;
            }
            if(number_cnt >= number_min){
                result++;
                for(int i=0; i<10; i++){
                    printf("%d ", pick[i]);
                }
                cout << endl;
            }
        }
        return;
    }
    
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(check[next] == false){
            cnt+=1;
            pick.push_back(next);
            check[next] = true;
            dfs(next);
            check[next] = false;
            pick.pop_back();
            cnt-=1;
        }
    }
}

void make_graph();
void init();
void make_time();

int main(){
    scanf("%d", &t);
    make_graph();
    
    for(int test_case = 1; test_case <= t; test_case++){
        //1. 초기화
        init();
        
        //2. 시간을 입력받는다.
        cin >> sdate >> stime;
        
        //3. 시간 정제
        make_time();

        //4. 탐색 시작
        check[start_index] = true;
        pick.push_back(start_index);
        cnt++;
        dfs(start_index);
        
        printf("#%d %d\n", test_case, result);
        
        
        for(int i=0; i<v[9].size(); i++){
            int next = v[9][i];
            cout << next << endl;
        }
    }
}

void init(){
    cnt = 0;
    result = 0;
    for(int i=0; i<36; i++) check[i] = false;
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
    upper_num = second/10;
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
        if(next>=0 && next<=3 && node >= 10 && node != 19) v[node].push_back(next);

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
