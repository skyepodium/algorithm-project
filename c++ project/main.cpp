#include <iostream>
#include <algorithm>
using namespace  std;

int n, v[4], cnt[4][4], num, max_idx=0, max_val=0;

int max3(int a, int b, int c){
    return max(max(a, b), c);
}

int main(){
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            scanf("%d", &num);

            v[j] += num;
            cnt[j][num]++;
        }
    }

    if(v[1] == v[2] == v[3]){
        for(int i=1; i<=4; i++){
            if(i==4) {
                cout << "Sfdkkkk" << endl;
            }
            if(cnt[1][i] == cnt[2][i] == cnt[3][i]){
                continue;
            }
            else{
                max_val = max3(cnt[1][i], cnt[2][i], cnt[3][i]);
                max_idx = 0;

                for(int i=1; i<=3; i++){
                    if(max_val == cnt[max_idx][i]){
                        max_idx = i;
                        break;
                    }
                }
            }
        }
    }
    else{
        max_val = max3(v[1], v[2], v[3]);
        max_idx = 0;

        for(int i=1; i<=3; i++){
            if(max_val == v[i]){
                max_idx = i;
                break;
            }
        }
    }
    printf("%d %d\n", max_idx, max_val);
}