#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string word;
        cin >> word;
        
        cout << "#" <<test_case << " ";
        
        for(int i=0; i<(int)word.size(); i++){
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') continue;
            else printf("%c", word[i]);
        }
        cout << endl;
        
    }
    return 0;
}

