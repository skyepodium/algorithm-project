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
        
        bool is_true = true;
        
        int size = (int)word.size();

        for(int i=0; i<size/2; i++){
            
            if(word[i] != word[size-1-i]){
                is_true = false;
                break;
            }
            
        }
        
        
        cout << "#" << test_case << " " << is_true << endl;
        
        
    }
    return 0;
}
