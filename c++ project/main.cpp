#include <iostream>
#include <vector>

#define lld long long int
using namespace std;

lld n, b;
vector<int> result;

int main(){
    scanf("%d %d", &n, &b);

    while(n>0){
        result.push_back(n%b);
        n /= b;
    }
    for(int i=(int)result.size()-1; i>=0; i--){
        if(result[i] >= 10){
            printf("%c", result[i] + 55);
        }
        else{
            printf("%d", result[i]);
        }
    }

}