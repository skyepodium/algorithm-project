#include <iostream>
#include <string>

using namespace std;

int main() {

    string word;
    cin >> word;
    
    int time = 0;
    for(int i=0; i<word.size(); i++){
        
        if(word[i] == 'A' || word[i] == 'B' || word[i] =='C'){
            time = time + 3;
        }else if(word[i] == 'D' || word[i] == 'E' || word[i] =='F'){
            time = time + 4;
        }else if(word[i] == 'G' || word[i] == 'H' || word[i] =='I'){
            time = time + 5;
        }else if(word[i] == 'J' || word[i] == 'K' || word[i] =='L'){
            time = time + 6;
        }else if(word[i] == 'M' || word[i] == 'N' || word[i] =='O'){
            time = time + 7;
        }else if(word[i] == 'P' || word[i] == 'Q' || word[i] =='R' || word[i] == 'S'){
            time = time + 8;
        }else if(word[i] == 'T' || word[i] == 'U' || word[i] =='V'){
            time = time + 9;
        }else if(word[i] == 'W' || word[i] == 'X' || word[i] =='Y' || word[i] == 'Z'){
            time = time + 10;
        }
        
    }
    cout << time << endl;
}
