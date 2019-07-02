#include <iostream>
#include <string>
#define max_int 200001
using namespace std;

int n, s, e, d[max_int][26], size;
char ch;
string word;

int main(){
    ios_base::sync_with_stdio(false);//
    
    cin >> word;
    for(int k=0; k<26; k++){
        for(int i=0; i<(int)word.size(); i++){
            int j = word[i] - 'a';
            d[i+1][k] = d[i][k];
            if(k == j){
                d[i+1][k]++;
            }
        }
    }
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> ch >> s >> e;
        s++;
        e++;
        cin.ignore();
        
        printf("%d\n", d[e][ch - 'a'] - d[s-1][ch - 'a']);
    }
    
}
