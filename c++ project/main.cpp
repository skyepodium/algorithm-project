#include <iostream>
#include <string>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 없음
//사용한 자료구조: string class, 1차원 배열

int stack[10000];

string check(string word){
    
    int size = 0;
    for(int i=0; i<word.size(); i++){
        
        stack[size] = word[i];
        
        if(word[i] == 40 || word[i] == 91 || word[i] == 123){
            size++;
        }else{
            
            if(size!=0){
                if(word[i] > 41){
                    if(word[i] != stack[size-1]+2){
                        return "NO";
                    }else{
                        stack[size-1] = 0;
                        size--;
                    }
                }else{
                    if(word[i] != stack[size-1]+1){
                        return "NO";
                    }else{
                        stack[size-1] = 0;
                        size--;
                    }
                }
            }else{
                return "NO";
            }
            
        }
        
    }

    if(size == 0){
        return "YES";
    }else{
        return "NO";
    }
}


int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        string word;
        cin >> word;
        
        cout << check(word) << endl;
        
    }
    
}

