#include <iostream>
#include <vector>
#include <algorithm>

#define max_int 16
using namespace std;

int l, c;
char a[max_int];
int vowel = 0;
int consonant = 0;
vector<char> pick;

void go(int index){
    
    if(index == c){
        if((int)pick.size() == l && vowel >= 1 && consonant >= 2){
            for(int i=0; i<(int)pick.size(); i++){
                printf("%c", pick[i]);
            }
            printf("\n");
        }
        return;
    }
    
    pick.push_back(a[index]);
    if(a[index] == 'a' || a[index] == 'e' || a[index] == 'i' || a[index] == 'o' || a[index] == 'u') vowel++;
    if(a[index] != 'a' && a[index] != 'e' && a[index] != 'i' && a[index] != 'o' && a[index] != 'u') consonant++;
    go(index + 1);
    pick.pop_back();
    if(a[index] == 'a' || a[index] == 'e' || a[index] == 'i' || a[index] == 'o' || a[index] == 'u') vowel--;
    if(a[index] != 'a' && a[index] != 'e' && a[index] != 'i' && a[index] != 'o' && a[index] != 'u') consonant--;

    go(index + 1);
}

int main(){
    scanf("%d %d", &l, &c);
    
    for(int i=0; i<c; i++){
        cin >> a[i];
    }
    sort(a, a+c);
    
    go(0);
}
