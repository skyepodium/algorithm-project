#include <iostream>

using namespace std;

//시간 복잡도: O(1)
//공간 복잡도: O(1)
//사용한 알고리즘: 없음
//사용한 자료구조: 없음


int p, q, r, s, w;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> p >> q >> r >> s >> w;
        
        int a = w*p;
        
        int b = 0;
        if(r>=w) b = q;
        else b = q + s*(w-r);
        
        cout << "#" << test_case << " ";
        if(a<b) cout << a << endl;
        else if(a>b) cout << b << endl;
        else cout << a << endl;
    }
    return 0;
}
