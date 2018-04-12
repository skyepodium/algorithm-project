#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(2^c)
//공간 복잡도: O(c)
//사용한 알고리즘: 재귀 함수
//사용한 자료구조: 1차원 배열

int l, c;
char word[15];
bool is_vowel[26];

void go(int index, vector<char> &pick, int vowel_cnt, int consonant_cnt){
    
    if(index == c){
        
        if(pick.size() == l){
            if(vowel_cnt >= 1 && consonant_cnt >=2){
                for(int i=0; i<pick.size(); i++){
                    cout << pick[i];
                }
                cout << endl;
            }
        }
        
        return;
    }
    
    //이번 인덱스 글자 포함
    pick.push_back(word[index]);
    go(index+1, pick, vowel_cnt + is_vowel[word[index]-97], consonant_cnt + !is_vowel[word[index]-97]);
    pick.pop_back();
    
    
    //이번 인덱스 글자 포함 안함
    go(index+1, pick, vowel_cnt, consonant_cnt);
    
}

int main(){
    
    cin >> l >> c;
    
    for(int i=0; i<c; i++){
        cin >> word[i];
    }
    
    sort(word, word+c);
    
    is_vowel[0] = is_vowel[4] = is_vowel[8] = is_vowel[14] = is_vowel[20] = true;
    
    vector<char> pick;
    go(0, pick, 0, 0);
}
