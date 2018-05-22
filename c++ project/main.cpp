#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;
        
        int hour = h1 + h2;
        int minute = m1 + m2;
        
        if(minute >= 60){
            minute = minute - 60;
            hour++;
        }
        
        if(hour > 12){
            hour = hour - 12;
        }
        
        cout << "#" << test_case << " " << hour << " " << minute << endl;
        
    }
    return 0;
}
