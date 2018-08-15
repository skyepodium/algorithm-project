#include <iostream>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: for문
//사용한 자료구조: 2차원 배열

int n;
int d[10][10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                d[i][j] = 0;
            }
        }
        
        cin >> n;
        int num = 1;
        int c_x = 0;
        int c_y = 0;
        int c_dir = 0;
        
        while(num<=n*n){
            if(d[c_x][c_y] == 0){
                d[c_x][c_y] = num;
                num++;
            }
            
            int n_x = c_x + dx[c_dir];
            int n_y = c_y + dy[c_dir];
            
            if(n_x>=0 && n_x<n && n_y>=0 && n_y<n){
                if(d[n_x][n_y] == 0){
                    c_x = n_x;
                    c_y = n_y;
                }else{
                    c_dir = (c_dir+3)%4;
                }
            }else{
                c_dir = (c_dir+3)%4;
            }
            
        }
        
        cout << "#" << test_case << endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << d[i][j] <<" ";
            }
            cout << endl;
        }
        
    }
    return 0;
}
