#include <iostream>

int a[501][501];
int d[501][501][2];


using namespace std;

int go(int i, int j, int dir){
 
    if(i == 0 || j == 0){
        return 0;
    }
 
    if(d[i][j][dir] > 0){
        return d[i][j][dir];
    }
    
    //위에서 올때
    if(dir == 0){
    if(a[i-1][j] == 0){
        d[i][j][dir] = (go(i-1, j, 0) + go(i-1, j, 1));
    }else if(a[i-1][j] == 1){
        d[i][j][dir] = 0;
    }else{
        d[i][j][dir] = go(i-1, j, 0);
    }
    }else{
    //왼쪽에서 올때
    if(a[i][j-1] == 0){
        d[i][j][dir] = (go(i, j-1, 1) + go(i, j-1, 0));
    }else if(a[i][j-1] == 1){
        d[i][j][dir] = 0;
    }else{
        d[i][j][dir] = go(i, j-1, 1);
    }
    }
    return d[i][j][dir];
}

int main(){
    
    int m, n;
    cin >> m >> n;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    d[1][1][1] = 1;
/*
//    d[1][1][0] = 1;//위
    d[1][1][1] = 1;//1,1에 왼쪽에서 왔다고 하자
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            
            if(i == 1 && j==1) continue;
            
            //위에서 올때
            if(a[i-1][j] == 0){
                d[i][j][0] = (d[i-1][j][0] + d[i-1][j][1]);
            }else if(a[i-1][j] == 1){
                d[i][j][0] = 0;
            }else{
                d[i][j][0] = d[i-1][j][0];
            }
            
            //왼쪽에서 올때
            if(a[i][j-1] == 0){
                d[i][j][1] = (d[i][j-1][1] + d[i][j-1][0]);
            }else if(a[i][j-1] == 1){
                d[i][j][1] = 0;
            }else{
                d[i][j][1] = d[i][j-1][1];
            }
            
        }
    }
*/
    cout << go(m, n, 0) + go(m, n, 1) << endl;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cout << d[i][j][0] + d[i][j][1] << " ";
        }
        cout << endl;
    }

    
    
}
