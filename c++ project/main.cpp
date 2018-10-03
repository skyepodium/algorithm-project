#include <iostream>

using namespace std;

int t, m, d;
int month[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        scanf("%d %d", &m, &d);
        
        int day = month[m-1] + d;
        
        int result;
        if(day%7 == 1) result = 4;
        else if(day%7 == 2) result = 5;
        else if(day%7 == 3) result = 6;
        else if(day%7 == 4) result = 0;
        else if(day%7 == 5) result = 1;
        else if(day%7 == 6) result = 2;
        else result = 3;
        printf("#%d %d\n", test_case, result);
    }
    
    return 0;
}
