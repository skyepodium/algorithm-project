#include <iostream>
#include <string>

using namespace std;

int t, n, cnt;
string word;
bool check[26];


int main(){
    scanf("%d", &t);

    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);

        cnt = 0;
        for(int i=0; i<26; i++){
            check[i] = false;
        }


        for(int i=0; i<n; i++){
            cin >> word;
            check[word[0] - 'A'] = true;
        }

        for(int i=0; i<n; i++){
            if(check[i]){
                cnt++;
            }
            else{
                break;
            }
        }

        printf("#%d %d\n", test_case, cnt);
    }
}