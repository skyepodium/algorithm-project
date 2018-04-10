#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;

char word[15];

int main(){
    
    cin >> l >> c;
    
    for(int i=0; i<c; i++){
        cin >> word[i];
    }
    
    sort(word, word+c);
    
    vector<int> v;
    for(int i=0; i<l; i++){
        v.push_back(1);
    }

    for(int i=0; i<c-l; i++){
        v.push_back(0);
    }
    
    do{
        
        int mo_cnt = 0;
        int ja_cnt = 0;
        int current_val = 0;
        bool is_increase = true;
        
        for(int i=0; i<c; i++){
            
            if(v[i] == 1){
                if(word[i]==97 || word[i]==101 || word[i]==105 || word[i]==111 || word[i]==117){
                    mo_cnt++;
                }else{
                    ja_cnt++;
                }
                
                if(current_val<word[i]){
                    current_val = word[i];
                }else{
                    is_increase = false;
                    break;
                }
            }
        }
        
        if(mo_cnt >= 1 && ja_cnt >= 2 && is_increase == true){
            for(int i=0; i<c; i++){
                if(v[i] == 1){
                    cout << word[i];
                }
            }
            cout << endl;
        }
        
        
    }while(prev_permutation(v.begin(), v.end()));

}
