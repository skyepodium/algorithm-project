#include <iostream>
#include <vector>
#include <string>
#define max_int 5
using namespace std;

int a[max_int][max_int], result = 0;
int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};
vector<string> number_list;

string number_to_string(int value) {
    string ret = "";
    
    char string_value = (char)value + 48;
    
    return ret + string_value;
}


void go(int x, int y, string s) {
    
    if((int)s.size() >= 6) {
        
        bool is_exist = false;
        
        for(int i=0; i<(int)number_list.size(); i++) {
            if(number_list[i] == s) {
                is_exist = true;
                break;
            }
        }
        
        if(!is_exist) {
            number_list.push_back(s);
            result++;
        }
        
        return;
    }
    
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= max_int || ny < 0 || ny >= max_int) continue;
        
        go(nx, ny, s + number_to_string(a[nx][ny]));
        
    }
}


int main(){
    for(int i=0; i<max_int; i++) {
        for(int j=0; j<max_int; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i=0; i<max_int; i++) {
        for(int j=0; j<max_int; j++) {
            go(i, j, number_to_string(a[i][j]));
        }
    }
    
    printf("%d\n", result);
}
