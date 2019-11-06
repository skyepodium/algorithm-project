#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define lld long long int
using namespace std;

const int max_int = 1001;

int t, n;
char hex_map[max_int][max_int], bit_map[max_int][max_int], temp_map[max_int][max_int];
set<lld> s;
vector<lld> v;

string group[2][10] = {
    {"0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011"},
    {"1110010", "1100110", "1101100", "1000010", "1011100", "1001110", "1010000", "1000100", "1001000", "1110100"}
};

string hex_to_bit(int num);

void set_bit_map();

void rotate_map();

void check_map(int m);

void init();

void find_num(int idx, int a_idx, int b_idx, int m);

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        
        init();
        
        for(int i=0; i<n; i++){
            scanf("%s", hex_map[i]);
        }
        set_bit_map();

        for(int i=0; i<n; i++){
            printf("%s", bit_map[i]);
        }
        
        for(int rotate_cnt = 0; rotate_cnt < 4; rotate_cnt++){
            rotate_map();
            for(int m = 1; m <= 3; m++){
                check_map(m);
            }
        }

        printf("#%d %d ", test_case, (int)v.size());
        sort(v.begin(), v.end());
        for(int i=0; i<(int)v.size(); i++){
            printf("%012lld ", v[i]);
        }
        printf("\n");
    }
}

void init(){
    s.clear();
    v.clear();
}

void rotate_map() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp_map[i][j] = bit_map[n-1-j][i];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            bit_map[i][j] = temp_map[i][j];
        }
    }
}

string hex_to_bit(int num){
    string ret = "0000";
    int idx = 3;
    
    while(num > 0){
        ret[idx] = (num%2) + 48;
        num /= 2;
        idx--;
    }
    return ret;
}

void set_bit_map(){
    for(int i=0; i<n; i++){
        int k_idx = 0;
        for(int j=0; j<n/4; j++){
            char curNum = hex_map[i][j];
            
            if(curNum <= 96) curNum -= 48;
            else curNum -= 87;
            
            string ret = hex_to_bit(curNum);
            for(int k=0; k<4; k++){
                bit_map[i][k_idx + k] = ret[k];
            }
            k_idx += 4;
        }
    }
}

void check_map(int m){
    for(int i=0; i<n; i++){
        
        for(int j=0; j<= n - 97*m; j++){

            int is_exist = 0;
            for(int k=0; k<m; k++){
                char s_1, s_2, s_3, s_4, c_1, c_2, c_3, c_4, c_5, e_1, e_2, e_3, e_4;
                s_1 = bit_map[i][j+0*m+k];
                s_2 = bit_map[i][j+1*m+k];
                s_3 = bit_map[i][j+2*m+k];
                s_4 = bit_map[i][j+3*m+k];
                
                c_1 = bit_map[i][j+46*m+k];
                c_2 = bit_map[i][j+47*m+k];
                c_3 = bit_map[i][j+48*m+k];
                c_4 = bit_map[i][j+49*m+k];
                c_5 = bit_map[i][j+50*m+k];

                e_1 = bit_map[i][j+93*m+k];
                e_2 = bit_map[i][j+94*m+k];
                e_3 = bit_map[i][j+95*m+k];
                e_4 = bit_map[i][j+96*m+k];
                
                if(s_1 == '0' && s_2 == '1' && s_3 == '0' && s_4 == '1' && c_1 == '0' && c_2 == '1' && c_3 == '0' && c_4 == '1' && c_5 == '0' && e_1 == '1' && e_2 == '0' && e_3 == '1' && e_4 == '0'){
                    is_exist++;
                }
            }
            if(is_exist == m){
                find_num(i, j+4*m, j+51*m, m);
            }
        }
    }
}

void find_num(int idx, int a_idx, int b_idx, int m){
    lld ret = 0;
    bool a_find = true, b_find = true;
    
        for(int i=0; i<6; i++){
            string curNum = "aaaaaaa";
            
            int is_exist = 0;
            int num = 0;
            
            for(int k=0; k<m; k++){
                curNum[0] = bit_map[idx][a_idx+0*m+k];
                curNum[1] = bit_map[idx][a_idx+1*m+k];
                curNum[2] = bit_map[idx][a_idx+2*m+k];
                curNum[3] = bit_map[idx][a_idx+3*m+k];
                curNum[4] = bit_map[idx][a_idx+4*m+k];
                curNum[5] = bit_map[idx][a_idx+5*m+k];
                curNum[6] = bit_map[idx][a_idx+6*m+k];

                for(int j=0; j<10; j++){
                    if(curNum == group[0][j]){
                        num = j;
                        is_exist++;
                    }
                }
            }
            if(is_exist != m) a_find = false;
            else ret = ret * 10 + num;
            a_idx = a_idx + 7*m;
        }
    
    for(int i=0; i<6; i++){
        string curNum = "aaaaaaa";
        
        int is_exist = 0;
        int num = 0;
        
        for(int k=0; k<m; k++){
            curNum[0] = bit_map[idx][b_idx+0*m+k];
            curNum[1] = bit_map[idx][b_idx+1*m+k];
            curNum[2] = bit_map[idx][b_idx+2*m+k];
            curNum[3] = bit_map[idx][b_idx+3*m+k];
            curNum[4] = bit_map[idx][b_idx+4*m+k];
            curNum[5] = bit_map[idx][b_idx+5*m+k];
            curNum[6] = bit_map[idx][b_idx+6*m+k];

            for(int j=0; j<10; j++){
                if(curNum == group[1][j]){
                    num = j;
                    is_exist++;
                }
            }
        }
        if(is_exist != m) b_find = false;
        else ret = ret * 10 + num;
        b_idx = b_idx + 7*m;
    }
    
    if(a_find && b_find){
//        auto iter = s.find(ret);
//        if(iter == s.end()){
//            s.insert(ret);
            v.push_back(ret);
//        }
    }

}
