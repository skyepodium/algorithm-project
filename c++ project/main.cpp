#include <iostream>
#include <queue>
#include <algorithm>
#define max_int 1501

using namespace std;

int a, b, c, d, nx, ny, nz, result = 0, arr[3];
bool check[max_int][max_int];

struct info{
    int x, y, z;
};

void sort_val(int &a, int &b, int &c) {
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    
    sort(arr, arr + 3);
    
    a = arr[0];
    b = arr[1];
    c = arr[2];
}

void bfs(int x, int y, int z) {
    queue<info> q;
    check[x][y] = true;
    q.push({x, y, d-(x+y)});
    
    while(!q.empty()) {
        info cur = q.front();
        q.pop();
        
        x = cur.x;
        y = cur.y;
        z = cur.z;
        
        if(x == y && y == z) {
            result = 1;
            break;
        }
        
        sort_val(x, y, z);
        
        if (y - x > 0) {
            nx = x * 2;
            ny = y - x;
            nz = z;
            
            if (nx < max_int && ny > 0) {
                sort_val(nx, ny, nz);
                
                if(!check[nx][ny]) {
                    check[nx][ny] = true;
                    q.push({nx, ny, nz});
                }
            }
        }
        
        if (z - x > 0) {
            nx = x * 2;
            ny = z - x;
            nz = y;

            if (nx < max_int && ny > 0) {
                sort_val(nx, ny, nz);
                
                if(!check[nx][ny]) {
                    check[nx][ny] = true;
                    q.push({nx, ny, nz});
                }
            }
        }
        
        if (z - y > 0) {
            nx = y * 2;
            ny = z - y;
            nz = x;

            if (nx < max_int && ny > 0) {
                sort_val(nx, ny, nz);
                
                if(!check[nx][ny]) {
                    check[nx][ny] = true;
                    q.push({nx, ny, nz});
                }
            }
        }
    }
}

int main () {
    scanf("%d %d %d", &a, &b, &c);
    d = a + b + c;
    
    sort_val(a, b, c);
    
    bfs(a, b, c);
    
    printf("%d\n", result);
}
