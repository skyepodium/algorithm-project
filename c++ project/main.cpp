#include <iostream>
#include <string>

using namespace std;

//시간 복잡도: O(1)
//공간 복잡도: O(n)
//사용한 알고리즘: 없음
//사용한 자료구조: 1차원 배열


int month[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int main(){
    
    int m, d;
    cin >> m >> d;
    int dayz = 0;
    if(m == 1) dayz = d - 1;
    else dayz = month[m-2] + d - 1;
    dayz = dayz%7;
    
    string result;
    if(dayz  == 0) result = "MON";
    else if(dayz == 1) result = "TUE";
    else if(dayz == 2) result = "WED";
    else if(dayz == 3) result = "THU";
    else if(dayz == 4) result = "FRI";
    else if(dayz == 5) result = "SAT";
    else result = "SUN";
    
    cout << result << endl;
    
}
