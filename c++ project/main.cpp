#include <iostream>
#include <vector>
#include <algorithm>
#define max_int 11
#define max_val 1001
using namespace std;

int n, m, k, d[max_int][max_int], a[max_int][max_int], dead[max_int][max_int], x, y, z, result;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1}, dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};


vector<int> v[max_int][max_int];

int main(){
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
            d[i][j] = 5;
        }
    }
    
    for(int i=1; i<=m; i++){
        scanf("%d %d %d", &x, &y, &z);
        v[x][y].push_back(z);
    }
    
    for(int year=1; year<=k; year++){
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                sort(v[i][j].begin(), v[i][j].end());
                d[i][j] += dead[i][j];
                dead[i][j] = 0;
            }
        }
        
        // 봄, 여름
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int k=0; k<(int)v[i][j].size(); k++){
                    // 남은 양분이 나이보다 클때
                    if(d[i][j] >= v[i][j][k]){
                        d[i][j] -= v[i][j][k];
                        v[i][j][k] += 1;
                    }
                    // 남은 양분이 나이보다 작을때
                    else{
                        
                        int idx = k;
                        int size = (int)v[i][j].size();
                        
                        for(int l=size-1; l>=idx; l--){
                            dead[i][j]+= (v[i][j][l] / 2);
                            v[i][j].pop_back();
                        }
                        break;
                    }
                }
            }
        }
        
        
        // 가을
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int s=0; s<v[i][j].size(); s++){
                    int tree = v[i][j][s];
                    if(tree % 5 != 0) continue;
                    
                    for(int k=0; k<8; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        
                        if(nx > n || nx < 1 || ny > n || ny < 1) continue;
                        
                        v[nx][ny].push_back(1);
                    }
                }
            }
        }
        
        // 겨울
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                d[i][j] += a[i][j];
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int s=0; s<v[i][j].size(); s++){
                if(v[i][j][s] < max_val) result++;
            }
        }
    }
    
    printf("%d\n", result);
}
