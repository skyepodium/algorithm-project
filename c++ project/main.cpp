#include <iostream>
#include <algorithm>

using namespace std;

int t, n, m, num;
int max_score, first_winner;

int main(){
    scanf("%d", &t);

    for(int test_case = 1; test_case <= t; test_case++){
        scanf("%d %d", &n, &m);

        max_score = 0;
        first_winner = 0;

        for(int i=1; i<=n; i++){
            int temp = 0;
            for(int j=1; j<=m; j++){
                scanf("%d", &num);
                temp += num;
            }

            if(temp > max_score){
                first_winner = 1;
                max_score = temp;
            }
            else if(temp == max_score){
                first_winner++;
            }

        }


        printf("#%d %d %d\n", test_case, first_winner, max_score);
    }


}