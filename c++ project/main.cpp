#include <iostream>
#include <queue>

using namespace std;

//시간 복잡도: O(nm)
//공간 복잡도: O(n)
//사용한 알고리즘: 없음
//사용한 자료구조: STL 큐

int main(){
    
    int n, m;
    cin >> n >> m;
    
    queue<int> q;
    
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    
    cout <<'<';
    
    while(!q.empty()){
        
        for(int i=0; i<m-1; i++){
            q.push(q.front());
            q.pop();
        }
        
        cout << q.front();
        if(q.size() != 1){
            cout << ", ";
        }
        q.pop();
    }
    
    cout <<'>'<<endl;
    
}
