#include <iostream>
#include <queue>

using namespace std;

int d[10];

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        
        queue<int> q;
        
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            char word;
            int num;
            cin >> word >> num;
            
            for(int i=0; i<num; i++){
                q.push(word);
            }
            
        }
        
        cout << "#" <<test_case<<" "<<endl;
        int i=0;
        while(!q.empty()){
            if(i == 10){
                cout << endl;
                i=0;
            }
            printf("%c", q.front());
            q.pop();
            i++;
        }
        cout << endl;
        
        
    }
    return 0;
}
