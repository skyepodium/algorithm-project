#include <iostream>
#include <algorithm>

#define max_int 21
using namespace std;

int n;
int lose[max_int];
int joy[max_int];
int d[max_int][101];

int from_health[max_int][101];
int from_joy[max_int][101];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &lose[i]);
    for(int i=1; i<=n; i++) scanf("%d", &joy[i]);

    if(100-lose[1] > 0) d[1][100-lose[1]] = joy[1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=100; j++){
            d[i][j] = d[i-1][j];
            from_health[i][j] = j;
            from_joy[i][j] = d[i-1][j];

            if(j+lose[i] <= 100){
                d[i][j] = max(d[i-1][j], d[i-1][j+lose[i]] + joy[i]);
                if(d[i-1][j] >  d[i-1][j+lose[i]] + joy[i]){
                    d[i][j] = d[i-1][j];
                    from_health[i][j] = j;
                    from_joy[i][j] = d[i-1][j];
                }
                else{
                    d[i][j] = d[i-1][j+lose[i]] + joy[i];
                    from_health[i][j] = j+lose[i];
                    from_joy[i][j] = d[i-1][j+lose[i]];
                }
            }
        }
    }

    int last_health = 0;
    int last_joy = 0;
    int result = 0;
    for(int j=1; j<=100; j++){
        if(result < d[n][j]){
            result = d[n][j];
            last_health = j;
            last_joy = d[n][j];
        }
    }
    printf("%d\n", result);

    cout << last_health << " " << last_joy << endl;
    int idx = n;
    while(idx != 0){
        cout << from_health[idx][last_health] << " " << from_joy[idx][last_health] << endl;
        last_health = from_health[idx][last_health];
        idx--;
    }


}