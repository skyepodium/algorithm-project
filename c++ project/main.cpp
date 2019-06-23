#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, a[26];
//string word;

int main(){
    
    scanf("%d", &n);
    
    cin.ignore();
    
    for(int test_case=1; test_case<=n; test_case++){
        memset(a, 0, sizeof(a));
        char word[1000];
        cin.getline(word,1000,'\n');
        for(int i=0; i<strlen(word); i++){
            
            int cur = word[i];
            
            // 소문자
            if(cur >= 97 && cur <=122){
                a[cur-97]++;
            }
            // 대문자
            else if(cur >= 65 && cur <=90){
                a[cur-65]++;
            }
        }
        
        bool p = true;
        bool d = true;
        bool t = true;
        
        for(int i=0; i<26; i++){
            if(a[i] < 3) t = false;
            if(a[i] < 2) d = false;
            if(a[i] < 1) p = false;
        }
        
        if(t) printf("Case %d: Triple pangram!!!\n", test_case);
        else if(d) printf("Case %d: Double pangram!!\n", test_case);
        else if(p) printf("Case %d: Pangram!\n", test_case);
        else printf("Case %d: Not a pangram\n", test_case);
    }
}
