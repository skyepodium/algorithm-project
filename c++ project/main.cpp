#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int d, h, m;
        cin >> d >> h >> m;
        
        int time_base = 671;
        int time_recognize = h*60 + m;
        
        int result = 0;
        
        if(d < 11) result = -1;
        else if(d == 11 && time_recognize < time_base) result = -1;
        else result = (d-11)*1440 + time_recognize - time_base;
        
        
        cout << "#" << test_case << " " << result << endl;
        
    }
    return 0;
}
