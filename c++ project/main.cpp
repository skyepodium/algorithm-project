#include <iostream>

using namespace std;

int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        int month1 = 0;
        for(int i=0; i<a-1; i++){
            month1 = month1 + day[i];
        }
        
        int first_day = month1 + b;

        int month2 = 0;
        for(int i=0; i<c-1; i++){
            month2 = month2 + day[i];
        }
        
        int second_day = month2 + d;
        
        cout << "#" << test_case << " " << second_day - first_day + 1<< endl;
        
    }
    return 0;
}
