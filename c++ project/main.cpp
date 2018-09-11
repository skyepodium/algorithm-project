#include <iostream>
#include <string>
#define max_int 101

using namespace std;

char d[101][101];
int n, k;

int main(){
    scanf("%d", &n);
    
    
    for(int i=0; i<n; i++){
        string word;
        cin >> word;
        for(int j=0; j<word.size(); j++){
            d[i][j] = word[j];
        }
    }
    
    scanf("%d", &k);
    if(k == 1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%c", d[i][j]);
            }
            printf("\n");
        }
    }
    
    else if(k == 2){
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                printf("%c", d[i][j]);
            }
            printf("\n");
        }
    }
    
    else{
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                printf("%c", d[i][j]);
            }
            printf("\n");
        }
    }


}
