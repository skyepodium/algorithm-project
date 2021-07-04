#include <string>

#define max_int 11
using namespace std;

bool check[max_int][max_int][max_int][max_int];


int get_dirs(char c){
    int res = 0;
    if (c == 'R') res = 0;
    else if(c == 'D') res = 1;
    else if(c == 'L') res = 2;
    else res = 3;
    
    return res;
}


int solution(string dirs) {
    int answer = 0;
    int x, y;
    x = 5; y = 5;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    for(int i=0; i<dirs.size(); i++) {
        char cur = dirs[i];
        int dir_num = get_dirs(cur);
        int nx = x + dx[dir_num];
        int ny = y + dy[dir_num];
        
        if(nx < 0 || nx > 10 || ny < 0 || ny > 10) continue;
        
        if (!check[x][y][nx][ny]) {
            check[x][y][nx][ny] = true;
            check[nx][ny][x][y] = true;
            answer += 1;
        }
        x = nx;
        y = ny;
    }
        
    return answer;
}

int main() {
    string a = "ULURRDLLU";
    int res = solution(a);
    
    cout << "res " << res << endl;
}
