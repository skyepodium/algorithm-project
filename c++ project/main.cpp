#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int t;
char a[5][5];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
vector<char> v;
map<string , int> m;

void dfs(int x, int y, int cnt){
    if(cnt == 7){
        string s;
        for(int i=0; i<7; i++){
            s += v[i];
        }
        if(m.find(s) == m.end()){
            m.insert(make_pair(s, 1));
        }

        return ;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<4 && ny>=0 && ny<4){
            v.push_back(a[nx][ny]);
            dfs(nx, ny, cnt+1);
            v.pop_back();
        }
    }
}

int main(){
    scanf("%d", &t);
    for(int test_case = 1; test_case<=t; test_case++){
        m.clear();
        v.clear();

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cin >> a[i][j];
            }
        }

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                v.push_back(a[i][j]);
                dfs(i, j, 1);
                v.pop_back();
            }
        }
        printf("#%d %d\n", test_case, (int)m.size());
    }
}