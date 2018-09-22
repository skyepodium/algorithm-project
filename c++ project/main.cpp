#include <iostream>
#include <cstring>
using namespace std;

int t;
char word[100];

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        scanf("%s", word);
        int length = (int)strlen(word);
 
        int last_number = word[length-1] - '0';

        bool is_odd = true;
        if(last_number%2 == 0) is_odd = false;
        
        if(is_odd) printf("#%d Odd\n", test_case);
        else printf("#%d Even\n", test_case);
    }
    
    return 0;
}
