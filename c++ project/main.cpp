#include <iostream>
#define max_int 21
#define lld long long int

using namespace std;

//n!의 갯수를 저장할 배열
lld facto[max_int];

//순열은 1~n까지의 수가 1번씩 사용된다.
//어떤 숫자가 사용되었는지 기록하는 배열
bool check[max_int];
int n, a, num;
lld k;

int main(){
    
    //1. 1! ~ 20!까지의 n! 갯수를 미리 계산한다.
    facto[1] = 1;
    for(int i=2; i<=20; i++){
        facto[i] = facto[i-1]*i;
    }
    
    scanf("%d", &n);
    
    scanf("%d", &a);

    //2. k번째 수열을 나타내는 n개의 수를 출력한다.
    if(a == 1){
        scanf("%lld", &k);
        
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=n; j++){
                if(check[j] == true) continue;
                
                if(facto[i] < k){
                    k = k - facto[i];
                }
                else{
                    printf("%d ", j);
                    check[j] = true;
                    break;
                }
                if(i==0 && check[j] == false){
                    printf("%d ", j);
                }
            }
        }
        printf("\n");
        
    }
    
    //3. 몇번째 수열인지 출력한다.
    else{
        lld result = 0;
        for(int i=n; i>=1; i--){
            scanf("%d", &num);
            
            for(int j=1; j<num; j++){
                if(check[j] == false){
                    result = result += facto[i-1];
                }
            }
            check[num] = true;
        }
        printf("%lld\n", result+1);
    }
}
